#include<stdio.h>
#include<stdlib.h>
int check(short** a,short size){
    int dub=size*2-1;
    int counter=0;
    int ver[size];
    int hor[size];
    int lptord[dub];
    int rptold[dub];    
    int verindex=0;
    int horindex=0;
    int flag;
    for(int i=0;i<size;i++){
        flag=1;
        for(int j=0;j<size;j++){
            flag &= a[j][i];
        }
        if(flag){
            hor[horindex++]=i;
        }
    }
    for(int i=0;i<size;i++){
        flag=1;
        for(int j=0;j<size;j++){
            flag &= a[i][j];
        }
        if(flag){
            ver[verindex++]=i;
        }
    }
    for(int i=0;i<size;i++){
        flag=1;
        for(int j=0;j<=i;j++){
            flag &= a[j][size-i-1+j];
        }
        lptord[i]=flag;
    }
    for(int i=size;i<dub;i++){
        flag=1;
        for(int j=i-size;j<size-1;j++){
            flag &= a[j+1][j-i+size];
        }
        lptord[i]=flag;
    }
    for(int i=0;i<size;i++){
        flag=1;
        for(int j=0;j<=i;j++){
            flag &= a[j][i-j];
        }
        rptold[i]=flag;
    }
    for(int i=size;i<dub;i++){
        flag=1;
        for(int j=i-size;j<size-1;j++){
            flag &= a[j+1][i-j-1];
        }
        rptold[i]=flag;
    }
    for(int i=0;i<verindex;i++){
        for(int j=0;j<horindex;j++){
            if(lptord[size-1+ver[i]-hor[j]]&&rptold[ver[i]+hor[j]]){
                counter++;
            }
        }
    }
    return counter;
}
int main(){
    short t,n;
    scanf("%hd",&t);
    scanf("%hd",&n);
    short arr[t][n];
        for(short j=0;j<n;j++){
            for(short k=0;k<n;k++){
                int a;
                scanf("%hd",&a);
                arr[j][k] = (a==255) ? 1 : 0;
            }
        }
        int c=check(arr,n);
        printf("%d\n",c);
    return 0;
}