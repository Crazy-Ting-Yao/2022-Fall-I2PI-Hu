#include<stdio.h>
#include<math.h>
int main(){
    long long int a;
    scanf("%lld",&a);
    int i=0;
    if(a==0){printf("0\n");return 0;}
    while(1){
        long long int x = pow(2,i);
        if(x>a){
            break;
        }
        else{
            i++;
        }
    }
    for(int r=i-1;r>=0;r--){
        if(pow(2,r)>a){
            printf("0");
        }
        else{
            printf("1");
            a-=pow(2,r);
        }
    }
    printf("\n");
    return 0;
}