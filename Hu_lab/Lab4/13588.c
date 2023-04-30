#include<stdio.h>
int main(){
    int arr[15][15];
    int arrlen, winlen;
    scanf("%d",&arrlen);
    scanf("%d",&winlen);
    for(int i=0;i<arrlen;i++){
        for(int j=0;j<arrlen;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int rep=arrlen-winlen+1;
    for(int i=0;i<rep;i++){
        for(int j=0;j<rep;j++){
            int max=arr[i][j];
            for(int a=0;a<winlen;a++){
                for(int b=0;b<winlen;b++){
                    if(arr[i+a][j+b]>max){
                        max = arr[i+a][j+b];
                    }
                }
            }
            printf("%5d",max);
        }
        printf("\n");
    }
    return 0;
}