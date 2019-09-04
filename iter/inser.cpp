#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int num[12];
int main(){
    int n, temp, sum;
    scanf("%d", &n);

    vector<int> op(n-1);

    for(int i=0;i<n;i++)
        scanf("%d", &num[i]);
        
    int cnt = 0;
    for(int i=0;i<4;i++){
        scanf("%d", &temp);
        for(int j = 0; j<temp; j++){
            op[cnt++] = i;
        }
    }
    int maxVal = -1000000000, minVal = 1000000000;

    
    do{
        sum = num[0];
        for(int i = 0 ;i<n-1;i++){
            switch(op[i]){
                case 0:
                sum += num[i+1];
                break;
                case 1:
                sum -= num[i+1];
                break;
                case 2:
                sum *= num[i+1];
                break;
                case 3:
                sum /= num[i+1];
                break;
            }
        }
        maxVal = max(maxVal, sum);
        minVal = min(minVal, sum);
    }while(next_permutation(op.begin(), op.end()));

    printf("%d\n", maxVal);
    printf("%d\n", minVal);
}