#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;
int n;
int p[1001];
void dp(){
    int maxV = 0;
    for(int i= 1; i<=n;i++){
        maxV = p[i];
        for(int j = 1; j<i; j++)
            maxV = max(maxV, p[j] + p[i - j]);
        p[i] = maxV;
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> p[i];
    }
    dp();
    printf("%d", p[n]);
}