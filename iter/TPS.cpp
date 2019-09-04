#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int map[11][11];
int main(){
    int N; 
    scanf("%d", &N);
    vector<int> list(N); 
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            scanf("%d", &map[i][j]);
        }
        list[i]= i;
    }
    int mini = 9999999;
    int sum = 0;
    int start = list[0];
    for(int i = 0; i<N-1; i++){
        if(map[start][list[i+1]]==0 ){
            sum = 9999999;
            break;
        }
        sum += map[start][list[i+1]];
        start = list[i+1];
    }
    if(map[start][list[0]]==0) sum = 9999999;
    sum += map[start][list[0]];
    mini = min(mini, sum);

    while(next_permutation(list.begin(), list.end())){
        sum = 0;
        start = list[0];
        for(int i = 0; i<N-1; i++){
            if(map[start][list[i+1]]==0){
                sum = 9999999;
                break;
            }
            sum += map[start][list[i+1]];
            start = list[i+1];
        }
        if(map[start][list[0]]==0) sum = 9999999;
        sum += map[start][list[0]];
        mini = min(mini, sum);
    }
    printf("%d", mini);
}