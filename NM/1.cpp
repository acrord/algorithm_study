#include<iostream>
#include<vector>
using namespace std;

int n, m;
bool number[10];

void NM(int depth, vector<int> ans){
    if(depth == m){
        for(int i =0; i<depth-1; i++){
            cout<<ans[i]<<" ";
        }
        cout<<ans[depth-1]<<"\n";
        return;
    }
    for(int i = 1; i<=n; i++){
        if(number[i]) continue;
        number[i] = true;
        ans.push_back(i);
        NM(depth + 1, ans);
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

    NM(0, ans);

}

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
bool number[10];
char d[20];
void NM(int depth){
    if(depth == m){
        d[depth * 2 - 1] = '\n';
        cout<<d;
        return;
    }
    for(int i = 0; i<n; i++){
        if(number[i]) continue;
        d[depth * 2] = i+1 + '0';
        d[depth * 2 + 1] = ' ';
        number[i] = true;
        NM(depth + 1);
        number[i] = false;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;    

    NM(0);

}