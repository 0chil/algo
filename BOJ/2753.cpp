// 2021.09.22 22:36:46
// 2753 https://boj.kr/2753
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int y;
    cin >> y;
    if(y%400==0 || (y%4==0 && y%100!=0)){
        cout << 1;
        return 0;
    }
    cout << 0;
    return 0;
}