#include<algorithm>
#include<vector>
#include <numeric>
#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>k;
        vector<long> v(k);
        long sum = 0;
        for(int j = 0; j<k; j++){
            cin>>v[j];
        }
        for(int j = 0; j<k; j++){
            for(int m = j + 1; m<k; m++){
                sum += __gcd(v[j], v[m]);
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}