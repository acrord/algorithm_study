#include<iostream>
using namespace std;
int n, k;
int ans[201][201] = {0, };
int dp(){
    int a, b, c;
    for(a = 1; a<=n; a++){
        ans[a][1] = 1, ans[a][0] = 1;
        for(b = 2; b<=k; b++){
            for(c = 1; c<=a;c++){
                ans[a][b] = (ans[a][b] + ans[c][b - 1]) % 1000000000;
            }
            ans[a][b] = (ans[a][b] + 1) % 1000000000;
        }
    }
}

int main(){
    cin >> n >>k;
    dp();
    cout<<ans[n][k];
}