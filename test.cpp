#include<iostream>
using namespace std;
int n, t, cnt = 0;
int main(){
    cin >> n;
    cin >> t;
    while(t != 0){
        if(t % 10 == 1) cnt++;
        t /=10;
    }
    cout<<cnt;
}