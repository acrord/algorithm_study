#include<iostream>
#define DIVINE 1000000000
using namespace std;
int n;
int num[101][10]={0,};


int dp(int k){
    if(k == 1) return 9;
    num[1][0] = 0;
    for(int i = 1;i<10; i++)
        num[1][i] = 1;

    for(int i = 2; i <= k; i++){
        num[i][0] = num[i - 1][1], num[i][9] = num[i-1][8];
        for(int j = 1; j<9;j++)
            num[i][j] = ((long long)(num[i - 1][j - 1] + num[i - 1][j + 1])) % 1000000000;
            
    }
    int sum = 0;
    for(int i = 0; i<10; i++){
        sum += num[k][i];
        sum %= DIVINE;
    }
    return sum;
}

int main(){
    cin >> n;
    cout<<dp(n);
}