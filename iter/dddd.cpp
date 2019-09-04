#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int T, i;
    char a[10];
    scanf("%d", &T);
    for(int k = 1; k<=T; k++){
        scanf("%s", a);
        for( i = 0;i<10; i++)
            if(a[i]>=48 && a[i]<=58) continue;
            else break;
        char d = '0';
        sort(a, a+i);
        int temp = 0;
        if(a[0]==d) temp++;
        for(int j =0; j<i; j++){
            if(a[j]==d) continue;
            else {
                temp++;
                d+=1;
            }
        }
        printf("#%d %d\n", k, temp);
    }
}