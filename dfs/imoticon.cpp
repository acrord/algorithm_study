#include<iostream>
#include<queue>
#include <string.h> 
using namespace std;
int s, cnt = 0, num, clip;
bool visited[1001][1001];
void bfs(){
    queue<pair<int, int>> q, nq;
    q.push(make_pair(1, 0));
    while(1){
        while(!q.empty()){
            num = q.front().first, clip = q.front().second;
            q.pop();
            if(num == s) return;
            visited[num][clip] = true;
            for(int i = 0; i<3;i++){
                switch(i){
                    case 0:
                    if(visited[num][num]) continue;
                    nq.push(make_pair(num, num));
                    break;
                    case 1:
                    if(num + clip>1000 || clip==0 || visited[num + clip][clip]) continue;
                    nq.push(make_pair(num + clip, clip));
                    break;
                    case 2:
                    if(num - 1 < 1 || visited[num - 1][clip]) continue;
                    nq.push(make_pair(num - 1, clip));
                    break;
                }
            }

        }
        if(nq.empty()) break;
        swap(q, nq);
        cnt++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for(int i = 1; i<=s; i++){
        memset(visited[i], false, sizeof(bool));
    }
    bfs();
    cout<<cnt;
}