#include<iostream>
using namespace std;
int n, minV = 100000000;
int map[11][11] = {0, };
bool visited[11] = {false, };
void dfs(int node, int depth, int sum){
    if(sum>=minV) return;
    if(depth == n){
        if(map[node][1] && minV > sum + map[node][1]) minV = sum + map[node][1];
        return;
    }
    visited[node] = true;
    for(int i = 2; i<=n; i++){
        if(visited[i] || !map[node][i]) continue;
        dfs(i, depth + 1, sum + map[node][i]);
    }
    visited[node] = false;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i<=n;i++)
        for(int j = 1; j<=n; j++)
            cin >> map[i][j];
    dfs(1, 1, 0);
    cout<< minV;
}