#include<stdio.h>
#include<stdlib.h>
int most(int* arr,int s,int e){
    int counter[501]={0};
    for(int i=s;i<=e;i++){
        counter[arr[i]]+=1;
    }
    int max=arr[0];
    for(int i=1;i<501;i++){
        if(counter[i]>counter[max]){
            max = i;
        }
        else if(counter[i]==counter[max]){
            if(i<max){
                max = i;
            }
        }
    }
    return max;
}
int main(){
    int n;
    scanf("%d",&n);
    int* dishes = (int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&dishes[i]);
    }
    int helptimes;
    scanf("%d",&helptimes);
    for(int i=0;i<helptimes;i++){
        int s,e;
        scanf("%d %d",&s,&e);
        printf("%d\n",most(dishes,s-1,e-1));
    }
    free(dishes);
    return 0;
}
