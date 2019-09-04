#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

bool aesc(vector<int> a, vector<int> b){
    auto tempa = a.begin()+1;
    auto tempb = b.begin()+1;
    return *tempa < *tempb;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0;
    deque<vector<int>> que;
    deque<vector<int>> que2;
    for(int i=0; i< jobs.size(); i++){
        que.push_back(jobs[i]);
    }
    sort(que.begin(), que.end());
    int flag =0;
    while(!que.empty()){
        vector<int> temp = que.front();
        que.pop_front();

        time += temp[1];//누적 시간
        answer += time - temp[0];
        deque<vector<int>> job;

        for(int i = 0; i <time ; i++){
            int count = 0;
            while(count<que.size()){
                if(que[count][0]==i){
                    job.push_back(que[count]);
                }
                if(que[count][0]>i) break;
                count++;
            }
        }
        sort(job.begin(), job.end(), aesc);

        int count = 0;
        vector<int> test;
        if(job.size()>0){
            test = job.front();
            while(!que.empty()){
            if(que.front()!=test){
                que2.push_back(que.front());
            }
            que.pop_front();
            }

            que.push_back(test);
            while(!que2.empty()){
                que.push_back(que2.front());
                que2.pop_front();
            }
        }
    }
    answer/=jobs.size();
    return answer;
}