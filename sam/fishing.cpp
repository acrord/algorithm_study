#include<iostream>
#include<queue>
#include<string.h>

using namespace std;

int dir[5][2] = {{0, 0}, {0, -1}, {0, 1}, {1, 0}, {-1, 0}}; //X  Y
int C, R, M;
int shark[101][101] = {0, };
struct fish {
    int r, c, s, d ,z;
    bool operator<(const fish& compare) const
    {
        return r > compare.r;
    }

};

int sum = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C >> M;
    fish f;
    priority_queue<fish> q, nq;
    for(int i = 0; i<M; i++){
        cin >> f.r >> f.c >> f.s >> f.d >> f.z;
        q.push(f);
    }
    
    for(int i = 1; i<=C; i++){
        bool first = true;
        fish parent, child;
        while(!q.empty()){
            parent = q.top();
            q.pop();
            //낚시왕이 잡음
            if(first && parent.c == i){
                sum += parent.z;
                first = !first;
                continue;
            }
            child.z = parent.z, child.s = parent.s;
            child.c = parent.c + parent.s * dir[parent.d][0] , child.r = parent.r + parent.s * dir[parent.d][1];
            switch(parent.d){
                case 1: //상
                    while(child.r <= 0) child.r += (R - 1) * 2;
                    if(child.r > R) child.d = 2, child.r = 2 * R - child.r;
                    else child.d = 1;
                break;
                case 2: // 하
                    child.r %= ((R - 1) * 2);
                    if(child.r > R) child.d = 1, child.r = 2 * R - child.r;
                    else child.d = 2;
                    if(!child.r){
                        child.d = 1;
                        child.r = 2;
                    }
                break;
                case 3: //우
                    child.c %= ((C - 1) * 2);
                    if(child.c > C) child.d = 4, child.c = 2 * C - child.c;
                    else child.d = 3;
                    if(!child.c){
                        child.d = 4;
                        child.c = 2;
                    }
                break;
                case 4: // 좌
                    while(child.c <= 0) child.c += (C - 1) * 2;
                    if(child.c > C) child.d = 3, child.c = 2 * C - child.c;
                    else child.d = 4;
                break;
            }
            if(shark[child.r][child.c] < child.z) {
                shark[child.r][child.c] = child.z;
                nq.push(child);
            }
        }
        if(nq.empty()) break;
        while(!nq.empty()){
            parent = nq.top();
            nq.pop();
            if(shark[parent.r][parent.c] > parent.z) continue;
            q.push(parent);
        }
        memset(shark, 0, sizeof(shark));
    }
    cout << sum;
}