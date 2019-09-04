#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int x, y, t, diff, sum = 0;
int dir[4][2] ={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int gongi[2][2] = {0,};
int check = 0;
struct node{
    int x, y;
};
queue<node> q, nq;
node front, child;
int map[1001][1001] = {0, }; //x, y
int map2[1001][1001] = {0, }; //x, y
int main(){
    scanf("%d %d %d", &y, &x, &t);
    for(int i = 1; i<=y; i++)
        for(int j = 1; j<=x; j++){
            scanf("%d", &map[j][i]);
            front.x = j, front.y = i;
            if(map[j][i] > 0) q.push(front);
            else if(map[j][i] == -1 && !gongi[0][0]) {
                map2[j][i] = -1, map2[j][i + 1] = -1;
                gongi[0][0] = j, gongi[0][1] = i;
                gongi[1][0] = j, gongi[1][1] = i + 1;
            }
        }
    printf("\n");
    while(t--){
        sum = 0;
        while(!q.empty()){
            front = q.front();
            q.pop();
            diff = map[front.x][front.y] / 5, map2[front.x][front.y] += map[front.x][front.y];
            map[front.x][front.y] = 0;
            for(int i = 0; i<4; i++){
                if(diff == 0) break;
                child.x = front.x + dir[i][0], child.y = front.y + dir[i][1];
                if((child.x == gongi[0][0] && child.y == gongi[0][1]) ||
                (child.x == gongi[1][0] && child.y == gongi[1][1]) ||
                !child.x || child.x == x + 1 || !child.y || child.y == y + 1) continue;
                if(map2[child.x][child.y] == 0) nq.push(child);
                map2[child.x][child.y] += diff, map2[front.x][front.y] -= diff;
                
            }
            nq.push(front);
        }
        // for(int i = 1; i<=y; i++){
        //     for(int j = 1; j<=x; j++)
        //         printf("%2d ", map2[j][i]);
        //     printf("\n");
        // }
        // printf("\n");

        while(!nq.empty()){
            check = 1;
            front = nq.front();
            nq.pop();

            //하단
            if(gongi[0][1] == front.y && gongi[0][0] < front.x && front.x != x) {
                check = 0;
                child.x = front.x + 1, child.y = front.y;
            }
            //우측
            else if(x == front.x && gongi[0][1] >= front.y && front.y != 1) {
                check = 0;
                child.x = front.x, child.y = front.y - 1;
            }
            //상단
            else if(front.y == 1 && x >= front.x && front.x != 1){
                check = 0;
                child.x = front.x - 1, child.y = 1;
            }
            //좌측
            else if(gongi[0][0] == front.x && gongi[0][1] > front.y) {
                check = 0;
                child.x = front.x, child.y = front.y + 1;
                if(child.y == gongi[0][1]) check = 2;
            }
            //상단
            else if(gongi[1][1] == front.y && gongi[1][0] < front.x && front.x != x) {
                check = 0;
                child.x = front.x + 1, child.y = front.y;
            }
            //우측
            else if(x == front.x && gongi[1][1] <= front.y && front.y != y) {
                check = 0;
                child.x = front.x, child.y = front.y + 1;
            }
            //하단
            else if(front.y == y && gongi[1][0] <= front.x && front.x != 1){
                check = 0;
                child.x = front.x - 1, child.y = y;
            }
            //좌측
            else if(gongi[1][0] == front.x && gongi[1][1] < front.y) {
                check = 0;
                child.x = front.x, child.y = front.y - 1;
                if(child.y == gongi[1][1]) check = 2;
            }
            // if(child.x == 7 && child.y == 1) cout<<map2[front.x][front.y] << " "<<map[child.x][child.y]<<"\n";
            if(check == 2) continue;
            if(check == 1) child.x = front.x, child.y = front.y;
            if(map[child.x][child.y]) continue;
            map[child.x][child.y] = map2[front.x][front.y];
            q.push(child);
            sum += map[child.x][child.y];
            map2[front.x][front.y] = 0;
        }
        // for(int i = 1; i<=y; i++){
        //     for(int j = 1; j<=x; j++)
        //         printf("%2d ", map[j][i]);
        //     printf("\n");
        // }
        // printf("\n");
    }
    cout<<sum;
    
}
