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

    vector<int> tt = list;
    if(next_permutation(tt.begin(), tt.end())){
        for(int i = 0 ; i<n - 1; i++){
            printf("%d ", tt[i]);
        }
        printf("%d\n", tt[n-1]);
    }else{
        printf("-1");
    }
    
    vector<int> prev = list;
    for(int i=n-1; i>0; i--){
        for(int j = 1; j<=i; j++){
            if(list[i]>list[i-j]){
                check = 1;
                int temp = list[i];
                list[i] = list[i-j];
                list[i-j] = temp;
                sort(list.begin()+i-j+1, list.end());
                for(int i = 0 ; i<n - 1; i++){
                    printf("%d ", list[i]);
                }
                printf("%d\n", list[n-1]);
                return 0 ;
            }
        }
    }
    if(check == -1){
        printf("-1");
        return 0;
    } 
}