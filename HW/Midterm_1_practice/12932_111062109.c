//12932
#include<stdio.h>
int main(){
    char c[501][501];
    int v,h;
    scanf("%d %d",&v,&h);
    for(int i=0;i<v;i++){
        scanf("%s",c[i]);
    }
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int pos;
        scanf("%d",&pos);
        for(int j=0;j<v;j++){
            if(c[j][pos-1]=='\\'){
                if(pos==h){
                    printf("Right!\n");
                    break;
                }
                else if(c[j][pos]=='/'){
                    printf("Stuck QQ\n");
                    break;
                }
                else{
                    pos++;
                }
            }
            else if(c[j][pos-1]=='/'){
                if(pos==1){
                    printf("Left!\n");
                    break;
                }
                else if(c[j][pos-2]=='\\'){
                    printf("Stuck QQ\n");
                    break;
                }
                else{
                    pos--;
                }                
            }
            if(j==v-1){
                printf("Position: %d\n",pos);
            }
        }
    }
    return 0;
}