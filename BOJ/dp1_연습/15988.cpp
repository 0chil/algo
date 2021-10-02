// 2021.09.18 22:14:26
// 15988 https://boj.kr/15988
#include <bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'009
long long dp[1'000'000];

long long f(int n)
{
    if(n<0) return 0;
    if (n == 0)
        return 1;
    long long &ret = dp[n];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int i = 1; i <= 3; i++)
    {
        ret += f(n - i) % MOD;
    }
    return ret = ret % MOD;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=0;i<=1'000'000;i++){
        dp[i] = -1;
    }
    while (t--)
    {
        int n;
        cin >> n;
        cout << f(n) << '\n';
    }
}