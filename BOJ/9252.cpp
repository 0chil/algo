// 2022.02.26 13:54:58
// 9252 https://boj.kr/9252
#include <bits/stdc++.h>
using namespace std;

string a, b;

int dp[1001][1001];

int f(int ai, int bi)
{
    if (ai >= a.length() || bi >= b.length())
        return 0;

    int &ret = dp[ai][bi];
    if (ret != -1)
        return ret;

    if (a[ai] == b[bi])
    {
        return ret = f(ai + 1, bi + 1) + 1;
    }

    int l = f(ai + 1, bi);
    int r = f(ai, bi + 1);
    return ret = max(l, r);
}

void d(int ai, int bi)
{
    if (ai >= a.length() || bi >= b.length())
        return;

    if (a[ai] == b[bi])
    {
        cout << a[ai];
        d(ai + 1, bi + 1);
        return;
    }

    if (dp[ai + 1][bi] > dp[ai][bi + 1])
    {
        d(ai + 1, bi);
    }
    else
    {
        d(ai, bi + 1);
    }
    return;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> a >> b;
    memset(dp, -1, sizeof(int)*1001*1001);
    cout << f(0, 0) << '\n';
    d(0, 0);
}