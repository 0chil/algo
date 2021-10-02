// 2021.09.22 22:39:24
// 14681 https://boj.kr/14681
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int y,x;
    cin>> y >> x;
    int q = -1;
    if(y>0){
        if(x<0){
            q=4;
        }
        else{
            q=1;
        }
    }
    else{
        if(x<0){
            q=3;
        }
        else{
            q=2;
        }
    }
    cout << q;
}