// 2021.09.25 23:27:17
// 1373 https://boj.kr/1373
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    stack<int> answer;
    string s;
    cin>> s;
    int sum=0;
    for(int i=s.size()-1,cnt=0;i>=0;i--,cnt++){
        sum += (s[i]=='1')*pow(2,cnt);
        if(i==0|| cnt == 2){
            answer.push(sum);
            sum =0;
            cnt =-1;
        }
    }

    while(!answer.empty()){
        cout << answer.top();
        answer.pop();
    }
}