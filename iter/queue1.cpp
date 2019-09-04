#include <string>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    vector<int> tw = truck_weights;
    int answer = 1;
    int count = 0;
    int sum = 0;
    int *complete = new int[tw.size()];
    for(int i=0; i<tw.size(); i++) complete[i]=0;
    deque<int> w;
    
    while(true){
        sum = 0;
        for(int i=0; i<w.size(); i++){
            sum+=w[i];
        }
        if(count==tw.size() && sum == 0) {
            break;
        }
        
        if(count< tw.size() && sum + tw[count] <= weight){
            w.push_back(tw[count]);
            count++;
        }
        
        
        for(int i = 0; i<count; i++){
            if(complete[i]!=bridge_length){
                complete[i]++;
                if(complete[i]==bridge_length){
                    w.pop_front();
                }
            }
        }
        answer++;
    }
    return answer;
}