   #include <cstdio>
   #include <vector>
   #include <algorithm>
   #include <stdio.h>
   #include <math.h>
   #include <iostream>
   #include <queue>
   using namespace std;

   queue<int> q;
   int n ,m;
   int map[2000][10001]={0,};

   vector <int> v1;
   vector <int> v2;
   bool visited[10001];
   bool bvisited[10001];
   void bfs(int input){
      while(!q.empty()){

         int a = q.front();
         v2.push_back(a);
         q.pop();
         for(int j = 1; j <=n ; j++){
            if(map[a][j]==1 && bvisited[j]==false){
               q.push(j);
               bvisited[j]=true;
            }

         }   

      }


   }

   void dfs(int input){
         if (visited[input]==false) {
               visited[input] = true;
               for(int j = 1; j <=n ; j++){
                  if (map[input][j]==1){
                     if(visited[j]==false){
                        v1.push_back(j);
                     }
                     dfs(j);         
                  }
               }
         }
   }
   int main() {
      int startv ;
       scanf("%d %d %d",&n, &m, &startv);

      for (int i = 0; i < m; i++) {
          int s = 0;
          int e = 0;
          scanf("%d %d", &s, &e);
          map[s][e]=1;
            map[e][s] =1; 
       }
      visited[startv] = false;
      bvisited[startv] = true;

      v1.push_back(startv);

      if(m ==1){
         for(int i=1 ;i<=n ;i++){
            if(map[i][startv] ==1){
               cout <<startv <<" "<< i ;
            }
         }   
      }else{
         dfs(startv);
         for(int i =0 ; i< v1.size(); i++){

            if(i== v1.size()-1){
               cout << v1[i] ;
            }else{
               cout << v1[i] <<" " ;
            }
      }

      }
      cout<<endl;
      //cout <<startv <<" ";
    q.push(startv);
    bfs(startv);
    for(int i =0 ; i< v2.size(); i++){
        if(i== v2.size()-1){
            cout << v2[i] <<endl;
            }else{
            cout << v2[i] <<" ";
            }
    }

       return 0;
   }