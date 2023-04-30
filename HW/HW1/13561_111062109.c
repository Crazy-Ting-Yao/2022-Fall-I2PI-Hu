#include<stdio.h>
#include<math.h>
int main(){
    int a;
    scanf("%d",&a);
    int i=0;
    while(1){
        int x = pow(2,i);
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