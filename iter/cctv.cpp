#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
bool visit[200];
int w, h;
int total; 
vector<vector<int>> map(8,vector<int>(8,0)); //사무실
void move(int x , int y , int dir){
   if(dir ==0){ //동
      for(int i =1; i<8; i++){
         if(map[x+i][y]==6)break;
         map[x+i][y] == -1;
         if(x+i == 8) break; 
      }
   }   
   else if(dir == 1){ 
      for(int i =1; i<8; i++){
         if(map[x-i][y]==6)break;
         map[x-i][y] == -1;
         if(x-i == 0) break; 
      }
   }else if (dir ==2){
      for(int i =1; i<8; i++){
         if(map[x][y-i]==6)break;
         map[x][y-i] == -1;
         if(y-i == 0) break; 
      }
   }else if (dir ==3){
      for(int i =1; i<8; i++){
         if(map[x][y+i]==6)break;
         map[x][y+i] == -1;
         if(y+i == 8) break; 
      }
   }
}

void dfs(int step ){
   
   for (int i = 0; i < w; i++) {
      for (int j = 0; j < h; j++){
         if(map[i][j]==1 ){
            for(int i=0; i<4 ; i++){
               move(i,j,i);
               step++;
               dfs(step);
            }
         }
      }
   }
}

int main() {
   
   cin>>w>>h;
   //vector<vector<int> > abc(w, vector<char>(h, 0));
   for (int i = 0; i < w; i++)
         for (int j = 0; j < h; j++)
               cin >>map[i][j];
   
   dfs(0);
   for (int i = 0; i < w; i++)
         for (int j = 0; j < h; j++)
               cout <<map[i][j];
    return 0;
}