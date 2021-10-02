// 2021.09.23 23:49:29
// 1699 https://boj.kr/1699
#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int f(int n)
{
    if(n<=3) return n;
    int &ret = dp[n];
    if (ret)
        return ret;
    ret = INT_MAX;
    for(int i=1;n>=i*i;i++){
        ret = min(ret, f(n-i*i)+1);
    }
    return ret;
    
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << f(n);
}