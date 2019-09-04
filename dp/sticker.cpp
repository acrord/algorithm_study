#include<iostream>
using namespace std;

int T, n;
int DP[2][100001], arr[2][100001];
// int flag;
// int num[100001][2];

inline int max(int a, int b){
    return a > b ? a : b;
}


// int dp(int k){
//     num[2][0] = num[1][1] + num[2][0], num[2][1] = num[1][0] + num[2][1];
//     for(int i=3; i<=k; i++){
//         num[i][1] += max(num[i - 2][0], num[i - 1][0]);
//         num[i][0] += max(num[i - 2][1], num[i - 1][1]);
//     }
//     return max(num[k][1], num[k][0]);
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 0 ; i<2; i++)
            for(int j = 1; j<=n; j++)
                cin >> arr[i][j];
        DP[0][1] = arr[0][1],DP[1][1] = arr[1][1];
        for(int i=2; i<=n;i++){
            DP[0][i] = max(DP[1][i-1], DP[1][i-2]) + arr[0][i];
            DP[1][i] = max(DP[0][i-1], DP[0][i-2]) + arr[1][i];
        }
        cout<<max(DP[0][n],DP[1][n]) <<"\n";
    }
}
