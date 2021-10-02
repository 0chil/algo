// 2021.09.14 22:55:20
// 10872 https://boj.kr/10872
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    int ans=1;
    for(int i=n;i>=1;i--){
        ans*=i;
    }
    cout << ans;
}