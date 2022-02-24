// 2022.02.24 17:56:51
// 9251 https://boj.kr/9251
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
        ret = f(ai + 1, bi + 1) + 1;
    }
    else
    {
        int l = f(ai + 1, bi);
        int r = f(ai, bi + 1);
        ret = max(l, r);
    }

    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    memset(dp,-1,sizeof(int)*1001*1001);
    cin >> a >> b;
    cout << f(0, 0);
}