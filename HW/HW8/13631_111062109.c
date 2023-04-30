#include<stdio.h>
int box[20];
int n;
int target;
int ways=0;
void recursion(int index,int counter){
    if(counter>target) return;
    if(counter==target){
        ways+=1;
        return;
    }
    for(int i=index;i>=0;i--){
        recursion(i,counter+box[i]);
    }
}
int main(){
    scanf("%d %d",&target,&n);
    for(int i=0;i<n;i++){
        scanf("%d",&box[i]);
    }
    recursion(n-1,0);
    printf("%d\n",ways);
    return 0;
}