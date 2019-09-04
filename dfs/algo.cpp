#include<iostream>
#include<queue>
#include<string.h>
#include<cmath>
using namespace std;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n, m;
int map[101][101];
bool visited[101][101];
struct node
{
    int b, y, x;
    bool operator<(const node& rhs) const
    {
        return b > rhs.b;
    }
};

void bfs(){
    priority_queue<node> q;
    node root;
    root.x = 1, root.y = 1, root.b = 0;
    visited[1][1] = true;
    q.push(root);
    node parent, child;
    while(!q.empty()){
        parent = q.top();
        q.pop();
        if(parent.x == n && parent.y == m){
            cout<<parent.b<<"\n";
            return;
        }
        for(int i = 0; i<4; i++){
            child.x = parent.x + dir[i][0], child.y = parent.y + dir[i][1], child.b = parent.b;
            if(map[child.y][child.x]) child.b++;
            if(child.x < 1 || child.y < 1 || child.x > n || child.y > m || visited[child.y][child.x]) continue;
            visited[child.y][child.x] = true;
            if(child.x == n && child.y == m)
            cout<< child.x <<" "<<child.y<<" "<< child.b <<"\n";
            q.push(child);
        }
    }
}

int main(){
    cin >>n>> m; // n == x m == y
    for(int i= 1; i<=m;i++)
        for(int j = 1; j<=n; j++)
            scanf("%1d", &map[i][j]);
            
    
    bfs();
}