#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, check = -1;
    scanf("%d", &n);
    vector<int> list(n);
    for(int i = 0 ; i<n;i++)
        scanf("%d", &list[i]);

    if(prev_permutation(list.begin(), list.end())){
        for(int i = 0 ; i<n - 1; i++){
            printf("%d ", list[i]);
        }
        printf("%d\n", list[n-1]);
    }else{
        printf("-1");
    }
}