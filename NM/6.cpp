#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int num[10];
bool number[10];
vector<int> d;
void NM(int start, int depth){
    if(depth == m){
        for(int i =0; i<m-1;i++){
            cout<<d[i]<<" ";   
        }
        cout<<d[m-1]<<"\n";
        return;
    }
    for(int i = start; i<n; i++){
        if(number[i]) continue;
        d.push_back(num[i]);
        number[i] = true;
        NM(i+1, depth + 1);
        d.pop_back();
        number[i] = false;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;    
    for(int i = 0 ;i<n; i++){
        cin >> num[i];
    }
    sort(num, num + n);
    NM(0, 0);

}