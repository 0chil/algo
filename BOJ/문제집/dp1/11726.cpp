// 2021.09.18 12:14:43
// 11726 https://boj.kr/11726
#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1002];

int f(int pos){
    int &ret = dp[pos];
    if(ret != -1) return ret;
    if(pos > n) return 0;
    if(pos == n) return 1;
    int sum =0;
    sum += f(pos+1);
    sum += f(pos+2);
    return ret = sum%10007;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;

    for(int i=0;i<n+2;i++){
        dp[i] = -1;
    }
    cout << f(0);
}
