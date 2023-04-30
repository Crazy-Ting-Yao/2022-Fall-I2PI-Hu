#include<stdio.h>
#include<math.h>
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        unsigned int s,e;
        unsigned int res=0;
        scanf("%u %u",&s,&e);
        if(s==e) {
            printf("%d\n",s);
            continue;
        }
        for(int i=0;i<32;i++){
            unsigned a = pow(2,i);
            if(s<a) break;
            if(e-s>a) continue;
            else{
                int b=e%(2*a);
                int c=s%(2*a);
                if((b>=a)&&(c>=a)) res+=a;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}