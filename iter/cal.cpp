#include <stdio.h>

int main(){
    int E,S,M;
    long count = 1;
    scanf("%d %d %d", &E, &S, &M);
    while(E!=1 || S !=1 || M !=1 ){
        count++;
        E--;
        S--;
        M--;
        if(E==0) E=15;
        if(S==0) S = 28;
        if(M==0) M = 19;
    }
    printf("%d", count);
    return 0;
}