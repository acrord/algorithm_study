#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int m,n, ans = 0;
int map[1001][1001];
int cnt = 0;
int day = 0;
int qsize = 0;
bool flag = false;
void bfs(queue<vector<int>> dq){
    while(!dq.empty()){
        if(cnt == ans) {
            flag = true;
            return;
        }
        if(!qsize) {
            qsize = dq.size();
            day++;
        }
        vector<int> front = dq.front();
        dq.pop();
        vector<int> p(2);
        p[1] = front[1];
        if(front[0]==0){//x좌표
            p[0] = front[0] + 1;
            if(map[p[0]][p[1]] == 0) {
                cnt++;
                map[p[0]][p[1]] = 1;
                dq.push(p);
            }
        } else if(front[0] == n-1){
            p[0] = front[0] - 1;
            if(map[p[0]][p[1]] ==0) {
                cnt++;
                map[p[0]][p[1]] = 1;
                dq.push(p);
            }
        } else{
            p[0] = front[0] - 1;
            if(map[p[0]][p[1]] ==0) {
                cnt++;
                map[p[0]][p[1]] = 1;
                dq.push(p);
            }
            p[0] = front[0] + 1;
            if(map[p[0]][p[1]] ==0) {
                cnt++;
                map[p[0]][p[1]] = 1;
                dq.push(p);
            }
        }

        p[0] = front[0];
        if(front[1]==0){//y좌표
            p[1] = front[1] + 1;
            if(map[p[0]][p[1]] ==0) {
                cnt++;
                map[p[0]][p[1]] = 1;
                dq.push(p);
            }
        } else if(front[1] == m-1){
            p[1] = front[1] - 1;
            if(map[p[0]][p[1]] ==0) {
                cnt++;
                map[p[0]][p[1]] = 1;
                dq.push(p);
            }
        } else{
            p[1] = front[1] - 1;
            if(map[p[0]][p[1]] ==0) {
                cnt++;
                map[p[0]][p[1]] = 1;
                dq.push(p);
            }
            p[1] = front[1] + 1;
            if(map[p[0]][p[1]] ==0) {
                cnt++;
                map[p[0]][p[1]] = 1;
                dq.push(p);
            }
        }
        qsize--;
    }
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    queue<vector<int>> dq;
    cin >> m >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j]!=-1) {
                ans++;
                if(map[i][j]==1)cnt++;
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(map[i][j] == 1){
                vector<int> dec(2);
                dec[0] = i;
                dec[1] = j;
                dq.push(dec);
            }
        }
    }
    bfs(dq);
    if(flag) cout<<day;
    else cout<<-1;
}