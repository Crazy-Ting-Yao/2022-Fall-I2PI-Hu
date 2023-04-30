#include<stdio.h>
#include<stdlib.h>
unsigned short tree[1001][1001];
unsigned short value[1001];
unsigned short res[1001];
int n,x,d;
int recursion(int x){
    unsigned short r = value[x];
    for(int i=1;i<=n;i++){
        tree[x][i]=0;
        if(tree[i][x]){
            r+=(recursion(i));
        }
    }
    res[x] = r;
    return r;
}
int main(){
    scanf("%d %d %d",&n,&x,&d);
    for(int i=1;i<=n;i++){
        scanf("%hu",&value[i]);
    }
    for(int i=1;i<n;i++){
        unsigned short a,b;
        scanf("%hu %hu",&a,&b);
        tree[a][b]=1;
        tree[b][a]=1;
    }
    res[1]=recursion(1);
    int flag=0;
    for(int i=1;i<=n;i++){
        if(abs(res[i]-x)<d){
            if(flag) printf(" ");
            printf("%d",i);
            flag=1;
        }
    }
    printf("\n");
    return 0;
}