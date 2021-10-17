// 2021.09.18 12:39:46
// 9095 https://boj.kr/9095
#include <bits/stdc++.h>
using namespace std;

int dp[11];

int f(int n){
    int &ret = dp[n];
    if(ret != -1) return ret;
    if(n==0) return 1;
    if(n<0) return 0;
    int sum=0;
    sum+=f(n-1);
    sum+=f(n-2);
    sum+=f(n-3);
    return ret = sum;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int t,n;
    cin >> t;
    for(int i=0;i<11;i++){
        dp[i] = -1;
    }
    while(t--){
        cin >> n;
        cout << f(n) << '\n';
    }

}