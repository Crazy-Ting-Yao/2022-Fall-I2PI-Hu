#include<stdio.h>
typedef struct {
    int x;
    int y;
}Steps;
int n,m;
Steps step[90000];
short map[300][300];
Steps alph[26];
short turnx[4]={1,0,-1,0};
short turny[4]={0,1,0,-1};
int que;
int BFS(int i){
    short x = step[i].x;
    short y = step[i].y;
    for(int j=0;j<4;j++){
        short newx= x+turnx[j];
        short newy= y+turny[j];
        if(newx>=0&&newy>=0&&newx<n&&newy<m){
            short k = map[newx][newy];
            if(k==-1){
                return 1;
            }
            if(k==1){
                map[newx][newy]=0;
                que++;
                step[que].x=newx;
                step[que].y=newy;
            }
            else if(k>=(int)'a'){
                map[newx][newy]=0;
                que++;
                step[que].x=alph[k-'a'].x;
                step[que].y=alph[k-'a'].y;
                map[step[que].x][step[que].y]=0;
            }            
        }
    }
    return 0;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char temp;
                scanf(" %c",&temp);
                if(temp=='.'){
                    map[i][j]=1;
                }
                else if(temp=='#'){
                    map[i][j]=0;
                }
                else if(temp=='$'){
                    map[i][j]=0;
                    step[0].x = i;
                    step[0].y = j;
                    que=0;
                }
                else if(temp=='&'){
                    map[i][j]=-1;
                }
                else if(temp<='Z'){
                    alph[temp-'A'].x = i;
                    alph[temp-'A'].y = j;
                    map[i][j]=1;
                }
                else{
                    map[i][j] = (int)temp;
                }
            }
        }
        int flag=0;
        for(int i=0;i<=que;i++){
            flag = BFS(i);
            if(flag) break;
        }
        if(flag){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
}