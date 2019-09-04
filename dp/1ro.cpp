#include<iostream>
using namespace std;
int n;
int num[1000001];
int dp(int n){
    if(n<=1) return 0;
    int n1 = dp(n/3) + n % 3 + 1;
    int n2 = dp(n/2) + n % 2 + 1;
    return n1> n2 ? n2 : n1;
    // num[0] = 0;
    // num[1] = 0;
    // num[2] = 1;
    
    // for(int i = 3; i<=1000000;i++){
    //     if(i%3 == 0) num[i] = min(num[i/3] + 1, num[i - 1] + 1);
    //     else if(i%2 == 0) num[i] = min(num[i - 1] + 1, num[i/2] + 1);
    //     else num[i] = num[i - 1] + 1;
    // }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    printf("%d", dp(n));
}