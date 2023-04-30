#include<stdio.h>
#include<string.h>
int DP[10][1000][1000];
int t;
int len;
char str[1001];
int check(int s,int e){
    for(int i=s;i<=(e-s)/2+s;i++){
        if(str[i]!=str[e-i+s]){
            return 0;
        }
    }
    return 1;
}
int recursion(int s,int e){
    if(DP[t][s][e]) return DP[t][s][e];
    if(check(s,e)) return 0;
    int min=10000;
    for(int i=s;i<e;i++){
        if(check(s,i)){
            int tmp = recursion(i+1,e)+1;
            if(tmp<min) min=tmp;
        }
    }
    DP[t][s][e]=min;
    return min;
}
int main(){
    scanf("%d",&t);
    while(t--) {
        scanf("%s",str);
        len = strlen(str);
        printf("%d\n",recursion(0,len-1));
    }
}