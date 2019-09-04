#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string.h>
#include <cmath>
using namespace std;

int N,L,R;
int A[51][51];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool B[51][51];
int C[51][51] = {0,};
int previous = 0, kk =0, cnt =1, mm =0;
class People{
    public:
    int x, y, cnt; 
    People(int a, int b, int cntt){
        x = a, y = b, cnt = cntt;   
    }
};
queue<People> q;
void bfs(){
   while(q.size()){
      People a = q.front();
      q.pop();   
      for(int i =0;i < 4 ; i++){
        int dy = a.y + dir[i][1] ;
        int dx = a.x + dir[i][0] ;
        int key = A[dy][dx];
        if(dy>=0 && dy <N && dx >=0 && dx <N &&  abs(key - A[a.y][a.x]) >=L && abs(key - A[a.y][a.x]) <=R && B[dy][dx]==false){
            People p = People(dx,dy,a.cnt); 
            q.push(p);
            B[dy][dx]=true;
            C[dy][dx]=a.cnt;
        }
      }       
   }
}

void op (int key){
   for(int k =1 ; k<= key;k++ ){
      int tot=0;
      int ccc=0;
      for(int i =0 ; i < N; i++){
         for(int j =0 ; j < N; j++){
            if(k == C[i][j]){
               tot += A[i][j];
               ccc++;
               A[i][j]= 0;
            }
            
         }
      }
      if(ccc != 0){   
         if(ccc == 1) 
         kk = previous + 1;
         for(int i =0 ; i < N; i++){
            for(int j =0 ; j < N; j++){
               if(A[i][j]==0){
                  A[i][j]=tot/ccc;
               }
            }
         }   
      }
      
      
   }
   memset(B, false, sizeof(B));
   memset(C, 0, sizeof(C));
}

int main() {
   scanf("%d %d %d", &N, &L,&R);
   
   for(int i =0 ; i < N; i++){
      for(int j =0 ; j < N; j++){
         scanf("%d",&A[i][j]);
      }
   }
   while(true){
      previous = kk;
      cnt = 1;
      for(int i =0; i< N ;i++){
         for(int j =0; j < N ; j++){
            if(B[j][i]==false){
               People p = People(i,j,cnt); 
               q.push(p);
               B[j][i] = true;
               C[j][i] = cnt;
               bfs();
               cnt++;
            }
         }
      }
      op(cnt - 1);
      if(previous == kk) break;
   }
   cout << kk;   
   return 0;
}