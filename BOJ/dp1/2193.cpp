// 2021.09.18 15:00:36
// 2193 https://boj.kr/2193
#include <bits/stdc++.h>
using namespace std;

long long dp[2][91];

long long f(int now, int n)
{
    if (n == 1)
        return 1;
    long long &ret = dp[now][n];
    if (ret != -1)
        return ret;

    ret = 0;
    if (now != 1)
        ret += f(1, n - 1);
    ret += f(0, n - 1);
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = dp[1][i] = -1;
    }

    cout << f(1,n);
}