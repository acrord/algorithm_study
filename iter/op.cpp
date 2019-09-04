#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    
    int S[21]={0, };
    int n, val;
    char op[6];
    scanf("%d", &n);
    while(n--){
        scanf("%s", op);
        switch(op[0]){
            case 'a':
            if(op[1]=='d'){
                scanf("%d", &val);
                S[val]=1;
            }else{
                for(int i = 1;i<=20;i++)
                    S[i] = 1;
            }
            break;
            case 'c':
                scanf("%d", &val);
                if(S[val]){
                    printf("1\n");
                }else{
                    printf("0\n");
                }
            break;
            case 't':
                scanf("%d", &val);
                if(S[val]) S[val] = 0;
                else S[val] = 1;
            break;
            case 'r':
                scanf("%d", &val);
                if(S[val]) S[val] = 0;
            break;
            case 'e':
                for(int i = 1;i<=20;i++)
                    S[i] = 0;
            break;
        }
    }
}