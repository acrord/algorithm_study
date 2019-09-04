#include <stdio.h>
#include <math.h>
using namespace std;
bool list[1000002];
void prime(int n){
    for(int i = 3; i <= sqrt(n); i++){
        for(int j = i * 3; j <= n; j += 2 * i){
            list[j] = true;
        }
    }
    return ;
}
void solution(int n){
    for(int i = 3; i < n; i += 2){
        if(!list[i] && !list[n - i] ){
            printf("%d = %d + %d\n",n,i,n-i);
            return;
        }
    }
    printf("Goldbach's conjecture is wrong.\n");
    return;
}
int main(){
    int n;
    scanf("%d", &n);
    prime(1000000);
    while(n!=0){
        solution(n);
        scanf("%d", &n);
    }
}