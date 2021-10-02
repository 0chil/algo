// 2021.10.02 23:58:08
// 8958 https://boj.kr/8958
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int acc = 1;
        int score = 0;
        for(auto& ox:s){
            if(ox == 'O'){
                score += acc++;
            }
            else{
                acc = 1;
            }
        }
        cout << score << '\n';
    }
}