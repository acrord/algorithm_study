#include <stdio.h>
#include <algorithm>
using namespace std; 
int array[9];

void answer(int a, int b){
    for(int i = 0 ; i<9;i++){
        if(i==a || i==b) continue;
        printf("%d\n", array[i]);
    }
}

int main(){
    
    int sum = 0;
    for(int i = 0 ; i<9 ; i++){
        scanf("%d", &array[i]);
        sum += array[i];
    }
    sort(array, array + 9);
    for(int i = 8;i>=0;i--){
        for(int j = i-1; j>=0; j--){
            if(sum-array[i]-array[j] == 100){
                answer(i, j);
                return 0;
            }
        }
    }
    
    return 0;
}