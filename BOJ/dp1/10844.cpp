// 2021.09.18 13:55:21
// 10844 https://boj.kr/10844
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000
long long dp[11][101];

long long f(int now, int n)
{
    if(now==-1|| now == 10) return 0;
    if (n == 1)
        return 1;
    long long &ret = dp[now][n];
    if (ret)
        return ret;
    return ret = (f(now - 1, n - 1) % MOD + f(now + 1, n - 1) % MOD)%MOD;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    long long ans=0;
    for (int i = 1; i < 10; i++)
    {
        ans += f(i,n) % MOD;
    }
    cout << ans % MOD;
}