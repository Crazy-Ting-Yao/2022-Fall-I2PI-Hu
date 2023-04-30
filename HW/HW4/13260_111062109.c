#include<stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        for(int j=0;j<num-i-1;j++){
            printf(" ");
        }
        for(int j=0;j<i+1;j++){
            printf("%d",j+1);
        }
        for(int j=i;j>=1;j--){
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}