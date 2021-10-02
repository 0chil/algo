// 2021.09.22 22:35:00
// 1330 https://boj.kr/1330
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    if(a==b){
        cout << "==";
    }
    else if(a<b){
        cout << "<";
    }
    else{
        cout << ">";
    }
}