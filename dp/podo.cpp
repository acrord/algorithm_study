#include<iostream>

using namespace std;

int n;
int num[10001];
int ans[10001][2];
int cnt = 2;
int tmp1 = 0, tmp2 = 0, tmp3 = 0;
int dp(int k){
    ans[0][0] = 0, ans[0][1] = 0; 
    ans[1][0] = num[1];
    ans[2][0] = ans[1][0] + num[2];
    ans[1][1] = 1;
    ans[2][1] = 2;
    for(int i = 3; i <= k; i++){
        tmp1 = 0, tmp2 = 0, tmp3 = 0;
        tmp1 = ans[i - 3][0] + num[i] + num[i - 1];
        tmp2 = ans[i - 2][0] + num[i];

        if(tmp1 > tmp2) {
            ans[i][0] = tmp1;
            ans[i][1] = 2;
        }
        else {
            ans[i][1] = 1;
            ans[i][0] = tmp2;
        }

        if(ans[i-2][1]!=2){
            tmp3 = ans[i - 2][0] + num[i - 1];
            if(tmp3 > ans[i][0]){
                ans[i][0] = tmp3;
                ans[i][1] = 0;
            }
        }

        if(ans[i - 1][0] >= ans[i][0]){
            ans[i][0] = ans[i - 1][0];
            ans[i][1] = 0;
        } 
        
    }
    return ans[k][0];
}

int main(){
    cin >> n;
    for(int i = 1; i<=n; i++)
        cin >> num[i];
    cout << dp(n);
}