// 2021.10.02 21:55:34
// 17298_3 https://boj.kr/17298
#include <bits/stdc++.h>
using namespace std;

class Elem{
    public:
    int number,index;
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,input;
    cin>> n;

    stack<Elem> s;
    vector<int> answer(n,-1);
    for(int i=0;i<n;i++){
        cin >> input;
        
        while(!s.empty() && s.top().number < input){
            answer[s.top().index] = input;
            s.pop();
        }
        s.push(Elem({input,i}));
    }

    for(auto& nge : answer){
        cout << nge << ' ';
    }
}