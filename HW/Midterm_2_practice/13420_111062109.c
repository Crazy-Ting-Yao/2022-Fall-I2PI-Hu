#include<stdio.h>
int list[100];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        list[i] = i;
    }
    while(k--){
        int a,b;
        scanf("%d %d",&a,&b);
        int temp = list[a];
        for(int i=0;i<n;i++){
            if(list[i]==temp){
                list[i]=list[b];
            }
        }
    }
    int list2[100]={0};
    for(int i=0;i<n;i++){
       list2[list[i]]=1;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(list2[i]){
            sum++;
        }
    }
    printf("%d\n",sum-1);
    return 0;
}