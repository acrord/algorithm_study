#include<iostream>
#include<stdio.h>
#include<queue>
#include<cmath>
using namespace std;
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; //y, x
int n, m, x, y, nx, ny, front;
int map[101][101];
int minVal = 99999;
void bfs(){
    queue<pair<int, int>> q;
    queue<pair<int, int>> nq;
    int cnt = 1;
    q.push(make_pair(1,1));
    map[1][1] = 0;
    while(1){
        while(!q.empty()){
            x = q.front().second, y = q.front().first;
            q.pop();
            if(y == n && x == m) {
                minVal = min(minVal, cnt);
                map[y][x] = 1;
                continue;
            }
            for(int i = 0; i<4;i++){
                nx = x + dir[i][1], ny = y + dir[i][0];
                if(nx==0 || ny==0 || nx == m+1 || ny == n+1 || !map[ny][nx]) continue;
                map[ny][nx] = 0;
                nq.push(make_pair(ny, nx));
            }
        }
        if(nq.empty()) break;
        swap(q, nq);
        cnt++;
    }
}


int main(){
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
            scanf("%1d",&map[i][j]);
    bfs();
    cout << minVal;
}