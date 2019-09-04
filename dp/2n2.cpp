#include<iostream>
using namespace std;
int n;
int num[1001]={0,};
int dp(){
    num[0] = 1, num[1] = 1, num[2] = 3;
    for(int i = 3; i<=1000; i++){
        if(i%2 == 0) num[i] = (num[i - 1] * 2 + 1)%10007;
        else num[i] = (num[i - 1] * 2 - 1)%10007;
    }
        
}


int main(){
    scanf("%d", &n);
    dp();
    printf("%d", num[n]);
}