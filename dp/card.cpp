#include<iostream>
#include<cmath>
using namespace std;
int n, p[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> p[i];
        for(int j = 1; j<=i/2; j++)
            p[i] = min(p[i], p[j] + p[i - j]);
    }
    printf("%d", p[n]);
}