#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}}; //y, x
int n,m, nx, ny, front;
int map[101][101];
int minVal = 99999;
void dfs(int y, int x, int cnt){
    map[y][x] = 0;
    if(y == n && x == m) {
        minVal = min(minVal, cnt);
        map[y][x] = 1;
        return;
    }
    for(int i = 0; i<4;i++){
        nx = x + dir[i][1], ny = y + dir[i][0];
        if(nx==0 || ny==0 || nx == m+1 || ny == n+1 || !map[ny][nx]) continue;
        dfs(ny, nx, cnt + 1);
    }
    map[y][x]=1;
}


int main(){
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
        for(int j = 1; j<=m; j++)
            scanf("%1d",&map[i][j]);
    dfs(1,1,1);
    cout << minVal;
}