// 2021.09.18 12:08:12
// 1463 https://boj.kr/1463
#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int f(int x)
{
    int &ret = dp[x];
    if (ret != -1)
        return ret;
    if (x == 1)
        return 0;
    int least = INT_MAX;
    if (x % 3 == 0)
        least = min(least, f(x / 3) + 1);
    if (x % 2 == 0)
        least = min(least, f(x / 2) + 1);
    return ret = min(least, f(x - 1)+1);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    cout << f(n);
}