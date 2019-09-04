#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
    int n; 
    cin>>n;
    vector<int> v(n);
    for(int i = 0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    vector<int> vv(v[0]+1);
    vv[0]=-1;
    vv[1]=-1;
    for(int i = 2 ; i<=sqrt(v[0]);i++){
        for(int j = i*2; j<=v[0]; j +=i){
            vv[j]=-1;
        }
    }
    int sum = 0;
    for(int i = 0; i<v.size(); i++){
        if(vv[v[i]] !=-1) sum++;
    }
    cout<<sum<<endl;
    return 0;
}