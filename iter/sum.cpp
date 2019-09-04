#include<stdio.h>
using namespace std;

int list[20];
int n, s;
int cnt = 0;
void check(int start, int sum){
    if(sum == s && start !=0){
        cnt++;
    }
    for(int i = start; i<n; i++){
        check(i + 1, sum + list[i]);
    }
}

int main(){
    
    scanf("%d %d", &n, &s);
    for(int i=0; i<n;i++)
        scanf("%d", &list[i]);
    
    check(0, 0);
    printf("%d", cnt);
}