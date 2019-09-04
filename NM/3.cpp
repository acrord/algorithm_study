#include<iostream>
#include<vector>
using namespace std;

int n, m;
bool number[8];
char d[15];

void NM(int depth){
    if(depth == m){
        d[depth * 2 - 1] = '\n';
        cout<< d;
        return;
    }
    for(int i = 1; i<=n; i++){
        d[depth * 2] = i + '0';
        d[depth * 2 + 1] = ' ';
        NM(depth+1);
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;    

    NM(0);

}