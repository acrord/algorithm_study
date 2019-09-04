#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, h, w, nh, nw, num = 0;
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int map[26][26];
vector<int> cnt; 

int bfs(int h, int w){
    int total = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(h, w));
    map[h][w] = 0;
    while(!q.empty()){
        h = q.front().first, w = q.front().second;
        q.pop();
        for(int i = 0; i<4 ;i++){
            nh = h + dir[i][0], nw = w + dir[i][1];
            if(nh<0 || nw <0 || nh==n || nw==n ||!map[nh][nw]) continue;
            q.push(make_pair(nh, nw));
            map[nh][nw] = 0;
            total++;
        }
    }
    cnt.push_back(total);
}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            scanf("%1d", &map[i][j]);
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n;j++){
            if(!map[i][j]) continue;
            bfs(i, j);
            num++;
        }
    cout<<num<<"\n";
    sort(cnt.begin(), cnt.end());
    for(int i = 0;i<num;i++)
        cout<<cnt[i]<<"\n";
}