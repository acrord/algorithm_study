#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int n, m;
int num[10];
bool number[10];
int d[20];

void NM(int depth){
    if(depth == m){     
        for(int i = 0; i<m-1;i++)
            cout<<d[i]<< " ";
        cout<<d[m-1]<<"\n";
        return;
    }
    bool ans[10001]={false,};
    for(int i = 0; i<n; i++){
        if(number[i] || ans[num[i]]) continue;
        ans[num[i]] = true;
        number[i] = true;
        
        d[depth] = num[i];
        
        NM(depth + 1);
        number[i] = false;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0 ;i<n; i++){
        cin >> num[i];
    }
    sort(num, num + n);

    NM(0);
}