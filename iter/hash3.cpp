#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// int solution(vector<vector<string>> clothes) {
//     int answer = 0;
//     int count = 0;
//     vector<string> types;
//     vector<string>::iterator it;
//     int clothesType[30] ={0,};
//     for(int i=0;i<clothes.size(); i++){
//         it = find(types.begin(), types.end(), clothes[i][1]);
//         if(it == types.end()){
//             types.push_back(clothes[i][1]);            
//             clothesType[count++]++;
//         }else{
//             clothesType[it-types.begin()]++;
//         }
//     }
//     cout << clothesType[0] << endl;
//     return answer;
// }
int main(){
    int *array = new int[3];
    array[0] = 0;
    array[1] = 0;
    cout << array[0]<<endl;
    cout << array[1]<<endl;
    return 0;
}
// array[0] = 0;
// array[1] = 0;
// cout << array[1]<<endl;