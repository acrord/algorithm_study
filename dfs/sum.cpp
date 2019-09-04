#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int w, h, x, y, nx, ny;
int map[51][51];
int dir[8][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

int dfs(int height, int weight){
    queue<pair<int, int>> q;
    q.push(make_pair(height, weight));
    while(!q.empty()){
        x = q.front().second, y = q.front().first;
        q.pop();
        for(int i =0; i<8; i++){
            nx = x + dir[i][0], ny = y + dir[i][1];
            if(nx<0 || ny<0 || nx == w || ny == h || !map[ny][nx]) continue;
            q.push(make_pair(ny, nx));
            map[ny][nx] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> w >> h;
    while(w || h ){
        int cnt = 0;
        for(int i = 0; i<h; i++)
            for(int j = 0; j<w; j++)
                cin>> map[i][j];
        
        for(int i =0; i<h;i++){
            for(int j = 0; j<w; j++){
                if(!map[i][j]) continue;
                cnt++;
                dfs(i, j);
                map[i][j] = 0;
            }
        }

        cout<<cnt<<"\n";
        cin >> w >> h;
    }
}