//13268
#include<stdio.h>
int main(){
    int n,l;
    int Domo=1;
    scanf("%d %d",&n,&l);
    int bed[1000];
    for(int i=0;i<n;i++){
        scanf("%d",&bed[i]);
    }
    for(int i=0;i<n-l+1;i++){
        int flag=1;
        for(int j=1;j<l-1;j++){
            if(bed[i]>=bed[i+j]||bed[i+l-1]>=bed[i+j]){
                flag=0;
                break;
            }
        }
        if(flag==0){
            continue;
        }
        for(int j=0;j<l;j++){
            printf("%d",bed[i+j]);
            if(j==l-1){
                printf("\n");
            }
            else{
                printf(" ");
            }
        }
        Domo=0;
    }
    if(Domo){
        printf("Domo\n");
    }
    return 0;
}