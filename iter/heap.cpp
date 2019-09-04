#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;

vector<int> solution(vector<string> operations) {
    string str = "This is a string";
    istringstream buf(str);
    istream_iterator<std::string> beg(buf), end;

    vector<string> tokens(beg, end); // done!

    vector<int> answer;
    deque<string> op;
    queue<int> que;
    while(!op.empty()){
        string operation = op.front();
        op.pop_front();
        switch(operation[0]){
            case "I": 
                
                // cout<<<<endl;
                // que.push(strtok(operation, "I "));
                cout<<que.front()<<endl;
                break;
            case "D": break;
        }
    }
    return answer;
}