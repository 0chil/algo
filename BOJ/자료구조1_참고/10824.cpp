// 2021.09.12 17:34:38
// 10824 https://boj.kr/10824
#include <bits/stdc++.h>
using namespace std;

long long str2int(const string &str){
    long long digit=1;
    long long ret = 0;
    for(int i=str.length()-1;i>=0;i--){
        ret+=(str[i]-'0')*digit;
        digit*=10;
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s[4];
    for(auto& si :s){
        cin >> si;
    }
    s[0]+=s[1];
    s[2]+=s[3];
    cout << str2int(s[0])+str2int(s[2]);
}