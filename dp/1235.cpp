#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T, t;
long long num[1000001][3]= {0,};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    num[1][1] = 1, num[1][2] = 0, num[1][3] = 0;
    num[2][1] = 0, num[2][2] = 1, num[2][3] = 0;
    num[3][1] = num[2][2] + num[2][3], num[3][2] = num[1][1] + num[1][3], num[3][3] = 1;

    for(int i = 4; i<=100000; i++){
        num[i][1] = (num[i - 1][2] + num[i - 1][3])%1000000009;
        num[i][2] = (num[i - 2][1] + num[i - 2][3])%1000000009;
        num[i][3] = (num[i - 3][1] + num[i - 3][2])%1000000009;
    }

    cin>>T;
    while(T--){
        cin >> t;
        cout<<((long long)(num[t][1] + num[t][2] + num[t][3]))%1000000009<<"\n";
    }
}