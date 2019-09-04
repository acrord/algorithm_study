#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
using namespace std;
vector<vector<int> > arr(501, vector<int>(501));
int w,h ;
int max(int a,int b){
   return a>b?a:b;
}
int one( int type){

   int maxh =0;
   int maxw =0;
   if(type ==0){
      for(int i =0 ; i < w-3 ; i++){
         
         for(int j =0 ;  j< h ; j++){
            int sum =0;
            for(int k =0 ; k<4;k++){
               
               sum += arr[i+k][j];
            
               maxw = max(sum,maxw);
            }
         }
      }
      for(int j =0 ;  j< h-3 ; j++){
         
         for(int i =0 ; i < 5 ; i++){
            int sum =0;
            for(int k =0 ; k<4;k++){
               
               sum += arr[i][j+k];
               maxh = max(sum,maxh);
            }
         }
      }
   }   

   return max(maxw,maxh);
}
int two(int type){
   int maxw =0;
   if(type ==1){
      for(int i =0; i< w-1 ; i++){
         for(int j =0; j< h-1 ; j++){
            int sum =0;
            
               sum += arr[i][j];
               sum += arr[i][j+1];
               sum += arr[i+1][j];
               sum += arr[i+1][j+1];
               maxw = max(sum,maxw);
         }
      }
   }
   return maxw;
}
int three(int type){
   int maxw =0;
   int maxh =0;
   if(type ==2){
      for(int i =0; i< w ; i ++){
         for(int j =0; j< h-2 ; j++){
            int sum =0;
            int sum1=0;
            int sum2=0;
            int sum3=0;
            int sum4=0;
            int sum5 =0;
            int sum6 =0;
            for(int k =0; k<3; k++){
               sum += arr[i][j+k];
            }
            
            if(i ==0){
                  sum1= sum+ arr[i+1][j];
                  sum2 = sum + arr[i+1][j+2];
                  sum5 = sum + arr[i+1][j+1];
               }else if(i == h){
                  sum3= sum+ arr[i-1][j];
                  sum4 = sum + arr[i-1][j+2];
                  sum5 = sum + arr[i-1][j+1];
               }else{
                  sum1= sum+ arr[i+1][j];
                  sum2 = sum + arr[i+1][j+2];
                  sum3= sum+ arr[i-1][j];
                  sum4 = sum + arr[i-1][j+2];
                  sum5 = sum + arr[i-1][j+1];
                  sum6 = sum + arr[i+1][j+1];
               }
            maxw = max(max(max(sum1,sum2),max(sum3,sum4)),maxw);
            maxw = max(max(sum5,sum6),maxw);
         }
         
      }
      for(int j =0; j< h ; j++){
         for(int i =0; i< w-2 ; i ++){
            int sum =0;
            int sum1=0;
            int sum2=0;
            int sum3=0;
            int sum4=0;
            int sum5 =0;
            int sum6 =0;
            for(int k =0; k<3; k++){
               sum += arr[i+k][j];
            }
            
            if(j ==0){
                  sum1= sum+ arr[i][j+1];
                  sum2 = sum + arr[i+2][j+1];
                  sum5 = sum + arr[i+1][j+1];
               }else if(j == h){
                  sum3= sum+ arr[i][j-1];
                  sum4 = sum + arr[i+2][j-1];
               sum5 = sum + arr[i+1][j-1];
               }else{
                  sum1= sum+ arr[i][j+1];
                  sum2 = sum + arr[i+2][j+1];
                  sum3= sum+ arr[i][j-1];
                  sum4 = sum + arr[i+2][j-1];
                  sum5 = sum + arr[i+1][j-1];
                  sum6 = sum + arr[i+1][j+1];
               }
            maxh = max(max(max(sum1,sum2),max(sum3,sum4)),maxh);
            maxh = max(max(sum5,sum6),maxh);
         }
         
      }
   }
   return max(maxw,maxh);
}
int four(int type){
   int maxw =0;int maxh =0; ; 
   
   if(type ==3){
      for(int i =1; i< w-1; i++){
         for(int j =0; j < h ; j++){
            int sum1 =0;
            int sum2 =0;
            int sum = arr[i][j] + arr[i][j+1];
            sum1 = sum + arr[i-1][j] + arr[i+1][j+1];
            sum2 = sum + arr[i-1][j+1] + arr[i+1][j];
            maxw= max(max(sum1,sum2),maxw);
         }
      }
      
      for(int j =1; j< h-1; j++){
         for(int i =0; i < w ; i++){
            int sum1 =0;
            int sum2 =0;
            int sum = arr[i][j] + arr[i+1][j];
            sum1 = sum + arr[i][j-1] + arr[i+1][j+1];
            sum2 = sum + arr[i+1][j-1] + arr[i][j+1];
            maxh= max(max(sum1,sum2),maxh);
         }
      }
   
   }
   return max(maxw,maxh);
}
int main() {

   scanf("%d %d", &w,&h);

   for (int i = 0; i < w; i++)
         for (int j = 0; j < h; j++)
               scanf("%d" , &arr[i][j]);
   int a =one(0);
   int b =two(1);
   int c = three(2);
   int d = four(3);
   int result = max(max(a,b), max(c,d));
   cout<< result<<endl;
}