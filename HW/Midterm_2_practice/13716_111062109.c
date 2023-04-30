#include<stdio.h>
int res[21];
int n,m;
int turnx[4]={1,0,-1,0};
int turny[4]={0,1,0,-1};
typedef struct {
    short posx;
    short posy;
    short steps;
}queue;
queue que[1000];
short map[20][20];
int qindex;
int bfs(int i){
    short x = que[i].posx;
    short y = que[i].posy;
    short steps = que[i].steps;
    for(int j=0;j<4;j++){
        int newx= x+turnx[j];
        int newy= y+turny[j];
        if(newx>=0&&newy>=0&&newx<n&&newy<m){
            if(map[newx][newy]==-1){
                return steps+1;
            }
            else if(map[newx][newy]){
                map[newx][newy]=0;
                qindex++;
                que[qindex].posx = newx;
                que[qindex].posy = newy;
                que[qindex].steps = steps+1;
            }
        }
    }
    return 0;
}
int main(){
    int q;
    scanf("%d %d %d",&n,&m,&q);
    short tempmap[n][m];
    char temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %c",&temp);
            switch(temp){
                case '-':
                tempmap[i][j]=-1;
                break;
                case '.':
                tempmap[i][j]=1;
                break;
                case 'X':
                tempmap[i][j]=0;
                break;
            }
        }
    }
    for(int i=0;i<q+1;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                map[j][k] = tempmap[j][k];
            }
        }
        qindex=0;
        scanf("%hd %hd",&que[0].posx,&que[0].posy);
        if(map[que[0].posx][que[0].posy]==-1){
            res[i]=0;
            continue;
        }
        que[0].steps=0;
        for(int j=0;j<=qindex;j++){
            res[i] = bfs(j);
            if(res[i]) break;
        }
    }
    for(int i=0;i<q;i++){
        printf("%d ",res[i]);
    }
    printf("%d\n",res[q]);
    int min=10000;
    for(int i=0;i<q;i++){
        if(res[i+1]<min){
            min=res[i+1];
        }
    }
    printf("%d\n",min-res[0]);
    return 0;
}   