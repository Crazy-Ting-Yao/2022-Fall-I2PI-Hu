#include<stdio.h>
char c[500][500];
int middle[8] = {0,1};
int cumulative[8] = {0,1};
void initialize_size() {
    for(int i = 2; i <= 7; i++) {
        middle[i] = 4 * cumulative[i-2] - middle[i-2] + 2;
        cumulative[i] = cumulative[i-1] + middle[i];
    }
}
int snowflake_size(int order) {
    return cumulative[order] + cumulative[order - 1];
}
void snowflake(int posx,int posy,int n){
    if(n==0)return;
    if(n==1){
        c[posx][posy]='#';
        return;
    }
    if((n%2)==0){
        for(int i=posx-(middle[n]/2)+1;i<=posx+(middle[n]/2);i++){
            for(int j=posy-(middle[n]/2)+1;j<=posy+(middle[n]/2);j++){
                c[i][j]='#';
            }
        }
        snowflake(posx-(middle[n]/2)-(middle[n-1]/2),posy-(middle[n]/2)-(middle[n-1]/2),n-1);
        snowflake(posx+1+(middle[n]/2)+(middle[n-1]/2),posy-(middle[n]/2)-(middle[n-1]/2),n-1);
        snowflake(posx-(middle[n]/2)-(middle[n-1]/2),posy+1+(middle[n]/2)+(middle[n-1]/2),n-1);
        snowflake(posx+1+(middle[n]/2)+(middle[n-1]/2),posy+1+(middle[n]/2)+(middle[n-1]/2),n-1);
        snowflake(posx-(middle[n]/2)-(middle[n-2]/2),posy,n-2);
        snowflake(posx+(middle[n]/2)+(middle[n-2]/2),posy,n-2);
        snowflake(posx,posy-(middle[n]/2)-(middle[n-2]/2),n-2);
        snowflake(posx,posy+(middle[n]/2)+(middle[n-2]/2),n-2);
    }
    else{
        for(int i=posx-(middle[n]/2);i<=posx+(middle[n]/2);i++){
            for(int j=posy-(middle[n]/2);j<=posy+(middle[n]/2);j++){
                c[i][j]='#';
            }
        }
        snowflake(posx-(middle[n]/2)-(middle[n-1]/2)-1,posy-(middle[n]/2)-(middle[n-1]/2)-1,n-1);
        snowflake(posx+(middle[n]/2)+(middle[n-1]/2),posy-(middle[n]/2)-(middle[n-1]/2)-1,n-1);
        snowflake(posx-(middle[n]/2)-(middle[n-1]/2)-1,posy+(middle[n]/2)+(middle[n-1]/2),n-1);
        snowflake(posx+(middle[n]/2)+(middle[n-1]/2),posy+(middle[n]/2)+(middle[n-1]/2),n-1);
        snowflake(posx-(middle[n]/2)-(middle[n-2]/2)-1,posy,n-2);
        snowflake(posx+(middle[n]/2)+(middle[n-2]/2)+1,posy,n-2);
        snowflake(posx,posy-(middle[n]/2)-(middle[n-2]/2)-1,n-2);
        snowflake(posx,posy+(middle[n]/2)+(middle[n-2]/2)+1,n-2);        
    }
}
int main(){
    int s;
    initialize_size();
    scanf("%d",&s);
    int size = snowflake_size(s);
    snowflake((size-1)/2,(size-1)/2,s);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(c[i][j]){
                printf("#");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}