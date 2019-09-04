#include<stdio.h>
#include<vector>
using namespace std;
int n, m, cnt = 0;
vector<int> link[1001];
bool ans[1001];


void dfs(int M){
    ans[M] = true;
    
    for(int next: link[M]){
        if(ans[next]) continue;
        
        dfs(next);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    vector<int> temp(2);
    
    for(int i = 0; i<m; i++){
        scanf("%d %d", &temp[0], &temp[1]);
        link[temp[0]].push_back(temp[1]);
        link[temp[1]].push_back(temp[0]);
    }
    for(int i = 1; i<=n; i++){
        if(!ans[i]){
            dfs(i);
            cnt++;
        }
    }
    printf("%d", cnt);

}