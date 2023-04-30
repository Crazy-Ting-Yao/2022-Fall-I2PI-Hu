#include<stdio.h>
int main(){
    long long int bullet, gun, bul;
    int s;
    scanf("%lld %lld %d",&gun,&bul,&s);
    double each;
    bullet = gun * bul;
    each = ((double)gun)/((double)s);
    printf("%lld\n%.2lf\n",bullet,each);
    return 0;
}