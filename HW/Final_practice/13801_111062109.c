#include<stdio.h>
#include<stdlib.h>
#include<math.h>
unsigned long long min=0;
unsigned long long* kinghts;
int n,k;
int main(){
    scanf("%d %d",&n,&k);
    kinghts = (unsigned long long*)malloc(sizeof(unsigned long long)*n);
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            short a;
            scanf("%hd",&a);
            kinghts[i] <<= 1;
            kinghts[i]+=a;
        }
    }
    unsigned long long target=1;
    for(int i=1;i<k;i++){
        target<<=1;
        target++;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((kinghts[i]|kinghts[j])==target) min++;
        }
    }
    printf("%llu\n",min);
    free(kinghts);
}