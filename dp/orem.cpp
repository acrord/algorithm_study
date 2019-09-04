#include<iostream>
#define DEVINE 10007
using namespace std;
int n;
int num[1001][10] = {0, };
int dp(int k){
    for(int i = 0; i<10; i++)
        num[1][i] = 1;

    for(int i = 2; i<=k; i++){
        for(int j = 0; j<10; j++ ){
            for(int h = 0; h<=j; h++){
                num[i][j] += num[i - 1][h];
                num[i][j] %= DEVINE;
            }
        }
    }
    int sum = 0;
    for(int i = 0; i<10; i++)
        sum += num[k][i];
    return sum%DEVINE;
}


int main(){
    cin >> n;
    cout<<dp(n);
}