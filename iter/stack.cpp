#include<stdio.h>
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int main(){
    vector<string> stack;
    string option;
    int N, count = 0;
    cin >> N;
    getline(cin, option);
    while(N--){
        getline(cin, option);
        istringstream iss(option);
        string token;
        count = 0;
        while(getline(iss, token, ' ')){
            if(token == "push"){
                continue;
            }else if(token=="top"){
                if(stack.size() == 0) printf("-1\n");
                else cout<<stack.back()<<endl;
            }else if(token == "size"){
                cout<<stack.size()<<endl;
            }else if(token == "empty"){
                if(!stack.empty())
                    cout<<0<<endl;
                else cout<<1<<endl;
            }else if(token == "pop"){
                if(stack.size() == 0){
                    printf("-1\n");
                    continue;
                }else{
                    cout<<stack.back()<<endl;
                    stack.pop_back();
                }
            }else{
                stack.push_back(token);
            }
        }
    }
}