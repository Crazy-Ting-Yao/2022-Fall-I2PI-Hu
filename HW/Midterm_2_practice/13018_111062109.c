#include <stdlib.h>

void sort(long long* a,int num){
    for(int i=num-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                long long temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return;
}
void array2d_sort(int row, int col, long long arr[][500]){
    int i;
    long long* a = calloc(sizeof(long long),row+col-1);
    int smaller = (row<col)? row:col;
    for(i=1;i<smaller;i++){
        for(int j=0;j<i;j++){
            a[j] = arr[j][col-i+j];
        }
        sort(a,i);
        for(int j=0;j<i;j++){
            arr[j][col-i+j] = a[j];
        }
    }
    if(row-col>=0){
        for(i=0;i<=row-col;i++){
            for(int j=0;j<col;j++){
                a[j] = arr[j+i][j];
            }
            sort(a,col);
            for(int j=0;j<col;j++){
                arr[j+i][j]= a[j];
            }
        }
    }
    else{
        for(i=0;i<=col-row;i++){
            for(int j=0;j<row;j++){
                a[j] = arr[j][j+i];
            }
            sort(a,row);
            for(int j=0;j<row;j++){
                arr[j][j+i]= a[j];
            }
        }
    }
    for(i=1;i<smaller;i++){
        for(int j=0;j<i;j++){
            a[j] = arr[row-i+j][j];
        }
        sort(a,i);
        for(int j=0;j<i;j++){
            arr[row-i+j][j] = a[j];
        }
    }
    free(a);
}