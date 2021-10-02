// 2021.09.30 22:14:41
// 10816 https://boj.kr/10816
#include <bits/stdc++.h>
using namespace std;

map<long long,long long> mp;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >>n;
    long long input;
    for(int i=0;i<n;i++){
        cin>> input;
        mp[input]++;
    }

    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> input;
        cout << mp[input] << ' ';
    }
}