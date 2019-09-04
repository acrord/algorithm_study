#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n, m;
int map[1001][1001];
bool visited[1001][1001][2];
bool flag = false;
int cnt = 0;
struct node {
    int x, y, d;
    bool b;
};

void bfs(){
    queue<node> q;
    node root;
    root.x = 1, root.y = 1, root.b = false, root.d = 1;
    visited[1][1][0] = true;
    q.push(root);
    node parent, child;
    while(!q.empty()){
        parent = q.front();
        q.pop();
        if(parent.x == m && parent.y == n){
            flag = true;
            cout << parent.d;
            return;
        }
        child.d = parent.d + 1;
        for(int i = 0; i<4;i++){
            child.x = parent.x + dir[i][0], child.y = parent.y + dir[i][1];
            if(child.x<1 || child.y<1 || child.x>m || child.y>n 
            || (map[child.y][child.x] && parent.b) || visited[child.y][child.x][parent.b]) continue;
            if(map[child.y][child.x]) child.b = true;
            else child.b = parent.b;
            // cout<<child.x <<" "<< child.y<<" "<<child.d<<"\n";
            visited[child.y][child.x][child.b] = true;
            q.push(child);
        }
    }
}


int main(){
    cin >>n>> m; // n == y m == x
    for(int i= 1; i<=n;i++)
        for(int j = 1; j<=m; j++){
            scanf("%1d", &map[i][j]);
            memset(visited[i][j], false, sizeof(bool));
        }
    
    bfs();
    if(!flag) cout << -1;
}