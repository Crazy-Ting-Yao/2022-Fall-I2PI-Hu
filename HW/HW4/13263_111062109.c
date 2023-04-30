#include<stdio.h>
int main(){
    int k;
    scanf("%d",&k);
    if(k%2==0){
        printf("Stop drawing fake diamonds!\n");
        return 0;
    }
    for(int i=0;i<k/2;i++){
        for(int j=0;j<k/2-i;j++){
            printf(" ");
        }
        for(int j=0;j<i*2+1;j++){
            printf("*");
        }
        printf("\n");
    }
    for(int i=0;i<k;i++){
        printf("*");
    }
    printf("\n");
    for(int i=k/2-1;i>=0;i--){
        for(int j=0;j<k/2-i;j++){
            printf(" ");
        }
        for(int j=0;j<i*2+1;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}