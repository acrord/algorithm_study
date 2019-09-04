#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct node{
    int x, y;
};

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int r,c, cnt = 0;
char map[51][51];
bool flag = false;
queue<node> q, nq, water, nwater;
node root, wat;
void bfs(){
    node parent, child, pnw, nw;

    while(1){
        while(!water.empty()){
            pnw = water.front();
            water.pop();
            for(int i = 0; i<4; i++){
                nw.x = pnw.x + dir[i][0], nw.y = pnw.y + dir[i][1];
                if(nw.x<0 || nw.x == c || nw.y<0 || nw.y == r || map[nw.y][nw.x] == 'X' || map[nw.y][nw.x] == 'D' || map[nw.y][nw.x] == '*') continue;
                map[nw.y][nw.x] = '*';
                nwater.push(nw);
            }
        }
        while(!q.empty()){
            parent = q.front();
            q.pop();

            if(map[parent.y][parent.x]  == 'D' ){
                flag = true;
                cout << cnt;
                return;
            }
            
            for(int i = 0; i<4; i++){
                child.x = parent.x + dir[i][0], child.y = parent.y + dir[i][1];
                if(child.x<0 || child.x == c || child.y<0 || child.y == r || map[child.y][child.x] == '*' || map[child.y][child.x] == 'X' || map[child.y][child.x] == 'S') continue;
                if(map[child.y][child.x] == '.') map[child.y][child.x] = 'S';
                nq.push(child);
            }
            
        }
        if(nq.empty()) break;
        cnt++;
        swap(q, nq);
        swap(water, nwater);
        
    }

    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r>>c;
    for(int i = 0; i<r;i++){
        cin >> map[i];
        for(int j = 0; j<c; j++){
            if(map[i][j] == 'S') {
                root.x = j, root.y = i;
            }
            else if(map[i][j] == '*'){
                wat.x = j, wat.y = i;
                water.push(wat);
            }
        }
    }
    q.push(root);
    bfs();
    if(!flag) cout <<"KAKTUS";
}