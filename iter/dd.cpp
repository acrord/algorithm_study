#include<stdio.h>
bool prime[10000001]={true,true, };
int main(){
    int M, N;
    scanf("%d %d", &M, &N);
    for(int i=2; i*i<=1000000; i++){
        for(int j=i*2; j<=1000000; j+=i){
            prime[j]=true;
        }
    }
    
    for(int i= M; i<=N; i++){
        if(!prime[i]) printf("%d\n", i);
    }
    return 0;
}