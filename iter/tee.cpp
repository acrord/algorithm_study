#include <cstdio>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int n ,a;
int map[21] = {0,};
int num[10];
int op[11];
char cmd[50];
string s;

int main() {
   scanf("%d",&n);
   for (int i = 0; i < n; i++) {
      scanf("%s", cmd);
      s = cmd;
      if (s !="all" && s !="empty"){
         scanf("%d",&a);      
      }
      if(s=="add"){
         map[a] =1; 
      }else if (s == "remove"){
         map[a] = 0;
      }else if (s == "check"){
         if(map[a] == 1){
            printf("1\n");
         }else if(map[a] ==0){
            printf("0\n");
         }
      }else if (s == "toggle"){
         if(map[a] == 1){
            map[a] =0;
         }else if(map[a] ==0){
            map[a] =1;
         }
      }else if (s == "all"){
         for(int i =0 ; i< 21 ; i++){
            map[i] =1;
         }
      }else if (s== "empty"){
         for(int i =0 ; i< 21 ; i++){
            map[i] =0;
         }
      }
   }
  
  
   
   return 0;
}
   