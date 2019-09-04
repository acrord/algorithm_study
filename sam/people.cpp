#include<iostream>
#include<queue>
#include<string.h>
#include<cmath>
using namespace std;

int n, L, R, map[51][51] = {0, }; 
int dir[4][2] ={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[51][51] = {false, };
int cnt = 0, sum = 0, previous = 0;
struct node
{
    int x, y;
};
node front, child;
queue<node> q, nq;

void bfs(){
    sum = 0;
    visited[front.y][front.x] = true;
    q.push(front);
    while(!q.empty()){
        front = q.front();
        nq.push(front);
        q.pop();
        sum += map[front.y][front.x];
        for(int i = 0; i < 4; i++){
            child.x = front.x + dir[i][0], child.y = front.y + dir[i][1]; 
            if(child.x < 1 || child.y < 1 || child.x > n 
            || child.y > n || visited[child.y][child.x] || abs(map[child.y][child.x] - map[front.y][front.x]) < L 
            || abs(map[child.y][child.x] - map[front.y][front.x]) > R) continue;
            visited[child.y][child.x] = true;
            q.push(child);
        }
    }
    if(nq.size()==1){
        nq.pop();
        return;
    }
    cnt = previous + 1;
    sum /= nq.size();
    while(!nq.empty()){
        front = nq.front();
        nq.pop();
        map[front.y][front.x] = sum;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> L >> R;
    for(int i = 1; i<=n; i++)//y
        for(int j = 1; j<=n; j++) // x
            cin >> map[i][j];
    while(1){
        sum = 0;
        previous = cnt;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(visited[i][j]) continue;
                front.x = j, front.y = i;
                bfs();
            }
        }
        memset(visited, false, sizeof(visited));
        if(previous == cnt) break;
    }
    cout << cnt;

    
}