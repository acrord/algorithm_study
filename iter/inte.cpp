#include<stdio.h>
int fact(int a){
    int mul = 1;
    if(a==0) return 1;
    while(a!=1){
        mul *= a;
        a--;
    }
    return mul;
}
int main(){
    int n, l, ans = 0;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &l);
        for(int i = 0; i<=l; i++){
            for(int j = 0; j<=l/2; j++){
                for(int k = 0; k<=l/3;k++){
                    if(i+j*2+k*3==l){
                        // printf("%d %d %d\n", i, j,k);
                        ans+=fact(i+j+k)/(fact(i)*fact(j)*fact(k));
                    } 
                }
            }
        }
        printf("%d\n", ans);
        ans = 0;
    }
    return 0;
}
// fact(i+j+k)/(fact(i)*fact(j)*fact(k))