#include<stdio.h>
char bun[20][20];
int n,m;
int min=10000;
void change(int x,int y){
    bun[x][y] = (bun[x][y]=='o') ? 'x' : 'o';
    if(x>0) bun[x-1][y] = (bun[x-1][y]=='o') ? 'x' : 'o';
    if(y>0) bun[x][y-1] = (bun[x][y-1]=='o') ? 'x' : 'o';
    if(x<n-1) bun[x+1][y] = (bun[x+1][y]=='o') ? 'x' : 'o';
    if(y<m-1) bun[x][y+1] = (bun[x][y+1]=='o') ? 'x' : 'o';
}
int check(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(bun[i][j]=='o') return 0;
        }
    }
    return 1;
}
void recursive(int steps,int index){
    if(min<=steps) return;
    if(check()){
        if(min>steps) min=steps;
        return;
    }
    for(int i=index+1;i<m*n;i++){
        int x = i/m;
        int y = i%m;
        change(x,y);
        recursive(steps+1,i);
        change(x,y);
    }
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %c",&bun[i][j]);
        }
    }
    recursive(0,-1);
    if(min==10000) printf("no solution\n");
    else printf("%d\n",min);
    return 0;
}
