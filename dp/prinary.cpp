#include<iostream>
// #define DEVINE 10007
using namespace std;
int n;

long long num[91][2]={0,};


long long dp(int k){
    num[1][0] = 0, num[1][1] = 1;
    for(int i = 2; i<=k; i++){
        num[i][0] = num[i - 1][1] + num[i - 1][0];
        num[i][1] = num[i - 1][0];
    }
    return num[k][0] + num[k][1];
}
int main(){
    cin >> n;
    cout<<dp(n);
}