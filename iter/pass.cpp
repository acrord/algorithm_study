#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int a, b;
char pass[16];
int select[16];
char col[5] = {'a', 'e', 'i', 'o', 'u'};

void check(int start, int depth){
    if(depth == a){
        int c = 0;
        string temp;
        for(int i = 0 ; i<a;i++){
            char t = pass[select[i]];
            temp +=t;
            for(int j = 0; j<5; j++)
                if(col[j]==t) {
                    c++;
                    break;
                }
        }
        if(c>= 1 && a-c >=2){
            cout<<temp<<endl;
        }
        return;
    }
    for(int i = start; i<b; i++ ){
        select[depth] = i;
        check(i+1, depth+1);
    }
}



int main(){
    scanf("%d %d", &a, &b);
    for(int i = 0 ; i<b; i++){
        cin >> pass[i];
    }
    sort(pass, pass + b);
    check(0, 0);

}