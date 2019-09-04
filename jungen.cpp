#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int t, n, x, y;
vector<pair<int, int>> map;
bool visited[5001] = {true, };
float sum = 0;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i<n; i++){
            cin >> x >> y;
            visited[x] = false;
            map.push_back(make_pair(x, y));
        }
        sort(map.begin(), map.end());

        pair<int, int> start = map[map.size()/2];
        visited[start.first] = true;
        for(int i = 0; i<n; i++){
            if(visited[map[i].first]) continue;
            visited[i] = true;
            sum += sqrt(pow(start.first - map[i].first, 2) + pow(start.second - map[i].second, 2));
            start = map[i];
            cout<<start.first <<" "<<start.second<<"\n";
        }
        sum += sqrt(pow(start.first - map[map.size()/2].first, 2) + pow(start.second - map[map.size()/2].second, 2));
        cout<<sum<<"\n";
        sum = 0;
        map.clear();
    }
}