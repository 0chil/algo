// 2021.09.12 17:53:32
// 11656 https://boj.kr/11656
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<string> postfix;
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        postfix.push_back(s.substr(i,s.length()-i));
    }

    sort(postfix.begin(),postfix.end(),less<string>());
    for(auto& str : postfix)
        cout << str << '\n';
}