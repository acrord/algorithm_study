#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
    int N;
    scanf("%d", &N);
    vector<int> list(N);
    for(int i = 0; i<N; i++){
        scanf("%d", &list[i]);
    }
    sort(list.begin(), list.end());
    vector<int> asc = list;
    sort(list.begin(), list.end(), greater<int>());
    vector<int> desc = list;
    int dcnt = 0;
    int acnt = 1;
    int first = asc[0];
    bool flag = true;
    bool ff = true;
    int suma = 0;
    int a, b, c, d;
    while(acnt + dcnt!=N){
        if(ff){
            a = desc[dcnt++];
            b = desc[dcnt++];
            suma += abs(a-first);
            suma += abs(b-first);
            ff = false;
            if(dcnt+acnt == N) {
                break;
            }
        }
        if(!flag){
            a = desc[dcnt++];
            suma += abs(a-c); 
            if(dcnt+acnt == N) {
                break;
            }
            b = desc[dcnt++];
            suma += abs(d-b); 
            flag = true;
        }else{
            c = asc[acnt++];
            suma += abs(c-a);
            if(dcnt+acnt == N) {
                break;
            }
            d = asc[acnt++];
            suma += abs(d-b);
            flag = false;
        }
    }

    dcnt = 1;
    acnt = 0;
    first = desc[0];
    flag = false;
    ff = true;
    int sumb = 0;

    while(acnt + dcnt!=N){
        if(ff){
            a = asc[acnt++];
            b = asc[acnt++];
            sumb += abs(a-first);
            sumb += abs(b-first);
            ff = false;
            if(dcnt+acnt == N) {
                break;
            }
        }
        if(!flag){
            c = desc[dcnt++];
            sumb += abs(a-c); 
            if(dcnt+acnt == N) {
                break;
            }
            d = desc[dcnt++];
            sumb += abs(d-b); 
            flag = true;
        }else{
            a = asc[acnt++];
            sumb += abs(c-a);
            if(dcnt+acnt == N) {
                break;
            }
            b = asc[acnt++];
            sumb += abs(d-b);
            flag = false;
        }
    }
    printf("%d", max(suma, sumb));
    return 0;
}