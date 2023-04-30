#include <math.h>
#include <stdio.h>
short DP[60000];
int res = 0;
int n, k;
int turnx[4]={1,0,-1,0};
int turny[4]={0,1,0,-1};
typedef struct{
    char B[3][3];
    int moves;
    int posx;
    int posy;
}que;
que queue[100000];
int qindex=0;
int cal(char B[][3]){
    int val = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            val *= 3;
            switch (B[i][j]) {
                case 'x':
                    val += 2;
                    break;
                case '1':
                    val += 1;
                    break;
            }
        }
    }
    return val;
}
void BFS(int i) {
    int x = queue[i].posx;
    int y = queue[i].posy;
    int moves = queue[i].moves;
    int val = cal(queue[i].B);
    if (DP[val] <= -1) {
        res-=DP[val];
    }
    if(DP[val] == 1){
        return;
    }
    DP[val] = 1;
    if (k == queue[i].moves) {
        return;
    }
    for(int p=0;p<4;p++){
        int newx= x+turnx[p];
        int newy= y+turny[p];
        if(newx>=0&&newy>=0&&newx<3&&newy<3){
            qindex++;
            for(int l=0;l<3;l++){
                for(int j=0;j<3;j++){
                    queue[qindex].B[l][j]=queue[i].B[l][j];
                }
            }
            queue[qindex].B[newx][newy] = queue[i].B[x][y];
            queue[qindex].B[x][y] = queue[i].B[newx][newy];
            queue[qindex].moves = moves+1;
            queue[qindex].posx = newx;
            queue[qindex].posy = newy;            
        }
    }
}
int main() {
    scanf("%d %d", &n, &k);
    char tmp;
    char B[3][3];
    for (int i = 0; i < n; i++) {
        int val = 0;
        for (int j = 0; j < 9; j++) {
            scanf(" %c", &tmp);
            val *= 3;
            switch (tmp) {
                case 'x':
                    val += 2;
                    break;
                case '1':
                    val += 1;
                    break;
            }
        }
        DP[val] -= 1;
    }
    int x, y;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf(" %c", &queue[0].B[i][j]);
            if(queue[0].B[i][j]=='x') {
                queue[0].posx = i;
                queue[0].posy = j;
            }
        }
    }
    queue[0].moves = 0;
    for(int i=0;i<=qindex;i++){
        BFS(i);
    }
    printf("%d\n", res);
    return 0;
}
