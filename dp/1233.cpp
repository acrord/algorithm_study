#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T, t;
int num[1000001]= {0,};
void dp(){
    num[0] = 0;
    num[1] = 1;
    num[2] = 2;
    num[3] = 4;
    for(int i = 4; i<1000001; i++)
        for(int j=1; j<=3;j++ ){
            num[i] += num[i-j];
            num[i] %= 1000000009;
        }
            
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    dp();
    cin>>T;
    while(T--){
        cin >> t;
        cout<<num[t]<<"\n";
    }
}