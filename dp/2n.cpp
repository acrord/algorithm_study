#include<iostream>
#include<vector>
using namespace std;
int n;
int num[1001];
int dp(){
    num[1] = 1, num[2] = 2;
    for(int i = 3; i<=1000; i++)
        num[i] = (num[i - 1] + num[i - 2]) % 10007;
}


int main(){
    scanf("%d", &n);
    dp();
    printf("%d", num[n]);
}