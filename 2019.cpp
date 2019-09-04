#include<iostream>
#include<vector>
using namespace std;
int n;

int dp(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    int n1 = dp(n-1) + 2;
    int n2 = dp(n-2) + 4;
    return n1 > n2 ? n1 : n2;
}


int main(){
    scanf("%d", &n);
    printf("%d",dp(n));
}