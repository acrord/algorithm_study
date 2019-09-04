#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int n, k, nn, cnt = 0;
bool checked[100001] = {false, };
void bfs(){
    queue<pair<int,int>> q, nq;
    q.push(make_pair(n, 0));
    while(1){
        while(!q.empty()){
            int front = q.front().first;
            int second = q.front().second;
            if(front == 1){
                checked[2] = true;
                nq.push(make_pair(2, second + 1));
            }
            if(front == k){
                cout << cnt-second;
                return;
            }
            checked[front] = true;
            q.pop();
            for(int i = 0; i<3; i++){
                switch(i){
                    case 0:
                    nn  = front - 1;
                    break;
                    case 1:
                    nn  = front + 1;
                    break;
                    case 2:
                    nn  = front * 2;
                    second += 1;
                    break;
                }
                if(nn < 0 || nn > 100000 || checked[nn]) continue;
                nq.push(make_pair(nn, second));
            }
        }
        if(nq.empty()) break;
        swap(q, nq);
        cnt++;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k;

    bfs();
}