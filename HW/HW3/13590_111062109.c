#include<stdio.h>
#include<math.h>
int main(){
    long long int ams;
    while(scanf("%lld",&ams)!=EOF){
        long long int counter=0;
        long long int l = ams, check = ams;
        int len;
        for(len=0;l;len++){
            l/=10;
        }
        for(int i=1;i<=len;i++){
            counter+=(pow((ams%10),len));
            ams/=10;
        }
        if(counter==check){
            printf("Yes it is.\n");
        }
        else{printf("No it is not.\n");}
    }
}