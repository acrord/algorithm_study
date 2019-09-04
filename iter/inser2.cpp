#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
int num[11];
int temp[4];
int ans [4] = {0, 0, 0, 0};
int n = 0;
int maxVal = -1000000000;
int minVal = 1000000000;
void check(int depth, int sum){
    if(depth == n-1){
        maxVal = max(maxVal, sum);
        minVal = min(minVal, sum);
        return;
    }
    for(int i = 0; i < 4; i++){
        if(ans[i] == temp[i]) continue;
        ans[i]++;
        switch(i){
            case 0:
            check(depth+1, sum + num[depth+1]);
            break;
            case 1:
            check(depth+1, sum - num[depth+1]);
            break;
            case 2:
            check(depth+1, sum * num[depth+1]);
            break;
            case 3:
            check(depth+1, sum / num[depth+1]);
            break;
        }
        ans[i]--;
    }
}

int main(){
    scanf("%d", &n);

    for(int i=0;i<n;i++)
        scanf("%d", &num[i]);
    
    
    for(int i=0;i<4;i++)
        scanf("%d", &temp[i]);

    check(0, num[0]);

    printf("%d\n", maxVal);
    printf("%d\n", minVal);
}