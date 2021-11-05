// 2021.11.05 22:35:31
// 1764 https://boj.kr/1764
#include <bits/stdc++.h>
using namespace std;
#define US
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    #ifdef UM
    unordered_map<string,bool> s;
    #elif defined M
    map<string,bool> s;
    #elif defined US
    unordered_set<string> s;
    #elif defined S
    set<string> s;
    #endif

    vector<string> dbj;
    while(n--){
        string input;
        cin>> input;
        #if (defined UM || defined M)
        s.insert(make_pair(input,true));
        #else (defined US || defined S)
        s.insert(input);
        #endif
    }

    while(m--){
        string input;
        cin>> input;
        if(s.find(input) != s.end()){
            dbj.push_back(input);
        }
    }

    sort(dbj.begin(),dbj.end());
    
    cout << dbj.size() << '\n';
    for(auto& name : dbj){
        cout << name << '\n';
    }

}