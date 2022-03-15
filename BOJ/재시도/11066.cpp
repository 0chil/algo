// 2022.03.15 16:52:57
// 11066 https://boj.kr/11066
#include <bits/stdc++.h>
using namespace std;

int cost[501];
int sum[501];
int dp[501][501];
int n;

int psum(int from, int to)
{
    if (from == 0)
        return sum[to];
    return sum[to] - sum[from - 1];
}

int f(int from, int to)
{
    if (from == to)
        return 0;

    int &ret = dp[from][to];
    if (ret != -1)
        return ret;
    ret = INT_MAX;
    for (int mid = from; mid < to; mid++)
    {
        ret = min(ret, f(from, mid) + f(mid + 1, to));
    }
    return ret += psum(from, to);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            cin >> cost[i];
            if (i > 0)
                sum[i] = sum[i - 1] + cost[i];
            else
                sum[0] = cost[i];
        }
        cout << f(0, n - 1) << '\n';
    }
}