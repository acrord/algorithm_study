#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;
int n; 
int t[15];
int p[15];
int maxVal = 0;

void check(int depth, int sum){
    if(depth == n){
        maxVal = max(maxVal, sum);
        return;
    }
    for(int i = depth; i<n; i++){
        if(i + t[i] <= n) check(i + t[i], sum + p[i]);
        else check(i + 1, sum);
    }
}

int main(){
    scanf("%d", &n);
    for(int i =0;i<n;i++)
        scanf("%d %d", &t[i], &p[i]);
    check(0, 0);
    printf("%d", maxVal);
}