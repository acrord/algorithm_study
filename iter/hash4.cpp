#include <string>
#include <vector>
#include <algorithm>
#include <map>
// #include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map <string, int> attributes;
    vector <string> Album;
    for(int i = 0;i< genres.size(); i++){
        attributes[genres[i]] += plays[i];
    }
    int count = 0;
    while(count != attributes.size()){
        int max = 0;
        string index;
        for(auto it = attributes.begin(); it != attributes.end(); it++){
            if(it -> second > max && find(Album.begin(), Album.end(), it->first)== Album.end()){
                max = it->second;
                index = it -> first;
            }
        }
        map <int, int, greater<int>> play;
        for(int i = 0;i< genres.size(); i++){
            if(genres[i]==index){
                play[plays[i]] = i;
            }
        }
        auto iter = play.begin();
        // cout << iter -> second << endl;
        // iter++;
        // cout << iter -> second << endl;
        answer.push_back(iter -> second);
        iter++;
        answer.push_back(iter -> second);
        Album.push_back(index);
        count++;
    }
    return answer;
}