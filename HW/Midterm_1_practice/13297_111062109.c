#include<stdio.h>
int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    short A[n][m];
    short AT[m][n];
    int res[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%hd",&A[i][j]);
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%hd",&AT[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            res[i][j]=0;
            for(int k=0;k<m;k++){
                res[i][j]+=A[i][k]*AT[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            printf("%d ",res[j][i]);
        }
        printf("%d\n",res[n-1][i]);
    }
    return 0;
}