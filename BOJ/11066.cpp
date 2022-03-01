// 2021.09.26 15:03:06
// 11066 https://boj.kr/11066
#include <bits/stdc++.h>
using namespace std;

int cost[501], sum[501], dp[501][501];
int k;

int psum(int from, int to)
{
    if (from == 0)
        return sum[to];
    return sum[to] - sum[from - 1];
}

// f() = from 부터 to까지 합치는 최소비용
// 덧셈을 직접 해보니, from 부터 to 까지는 범위를 어떻게 나누든 더하게 된다.
// (범위를 나누는 대로 2번 더해지는 놈들이 생김)
int f(int from, int to)
{
    if (from == to)
        return 0;
    int &ret = dp[from][to];
    if (ret)
        return ret;
    ret = 987654321;
    for (int mid = from; mid < to; mid++)
    {
        int left = f(from, mid);
        int right = f(mid + 1, to);
        ret = min(ret, left + right);
    }
    return ret += psum(from, to);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> cost[i];
            if (i == 0)
                sum[i] = cost[i];
            else
                sum[i] = sum[i - 1] + cost[i];
        }
        cout << f(0, k - 1) << '\n';
        memset(dp,0,sizeof(dp));
    }
}