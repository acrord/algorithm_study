#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m, a, b;
vector<int> link[2001];
bool ans[2001];
bool check = false;
void dfs(int m, int depth){
    ans[m] = true;
    if(depth == 5) {
        check = true;
        return;
    }
    for(int i : link[m]){
        if(!ans[i]){
            dfs(i, depth + 1);
        }
    }
    ans[m] = false;
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        link[a].push_back(b);
        link[b].push_back(a);
    }
    for(int i = 1;i<=n;i++){
        dfs(i, 1);
        if(check){
            cout<<1;
            return 0;
        }
    }
    
    cout<<0;
}