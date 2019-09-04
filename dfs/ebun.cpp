#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n;
int v,e, a,b;
bool first, flag = false;
vector<int> link[20001];

void bfs(){
    int color[20001]={0, };
    queue<int> que;
    for(int i=1; i<=v; i++){
        if(!color[i]) color[i] = 1;
        que.push(i);
        while(!que.empty()){
            int front = que.front();
            int next;
            que.pop();
            for(int j = 0;j<link[front].size();j++){
                next = link[front][j];
                if(!color[next]){
                    if(color[front] == 1) color[next] = 2;
                    else color[next] = 1;
                    que.push(next);
                }
                else if(color[next] == color[front]) {
                    flag = true;
                    return;
                }
            }
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while(n--){
        flag = false;
        
        cin >> v >> e;
        for(int i =0; i<e;i++){
            cin >> a >> b;
            link[a].push_back(b);
            link[b].push_back(a);
        }
        
        bfs();

        if(flag) cout<<"NO\n";
        else cout<<"YES\n";

        for(int i =0; i<=v; i++)
            link[i].clear();
    }
}