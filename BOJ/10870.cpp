// 2021.10.30 23:54:08
// 10870 https://boj.kr/10870
#include <bits/stdc++.h>
using namespace std;
int n;

int f(int a){
    if(a==0) return 0;
    if(a==1) return 1;
    return f(a-1)+f(a-2);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    cout << f(n);
}