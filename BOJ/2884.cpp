// 2021.09.22 22:47:08
// 2884 https://boj.kr/2884
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,m;
    cin >> h >> m;
    if(m<45){
        m = 60 + (m-45);
        if(h<1){
            h=23;
        }
        else{
            h--;
        }
    }
    else{
        m-=45;
    }
    cout << h << ' ' << m;
}