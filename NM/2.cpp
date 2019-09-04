#include<iostream>
#include<vector>
using namespace std;

int n, m;
bool number[10];

void NM(int start, int depth, vector<int> ans){
    if(depth == m){
        for(int i =0; i<depth-1; i++){
            cout<<ans[i]<<" ";
        }
        cout<<ans[depth-1]<<"\n";
        return;
    }
    for(int i = start; i<=n; i++){
        if(number[i]) continue;
        number[i] = true;
        ans.push_back(i);
        NM(i+1, depth + 1, ans);
        ans.pop_back();
        number[i] = false;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;    
    vector<int> ans;

    NM(1, 0, ans);

}