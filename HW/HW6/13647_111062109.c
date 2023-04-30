#include<stdio.h>
int main(){
    int G0,G1,n;
    scanf("%d %d %d",&G0,&G1,&n);
    for(int i=0;i<n-1;i++){
        int temp = G0-G1;
        G0 = G1;
        G1 = temp;
    }
    if(n==0){
        printf("%d\n",G0);
        return 0;
    }
    printf("%d\n",G1);
    return 0;
}