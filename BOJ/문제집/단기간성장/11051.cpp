// 2022.02.28 17:14:53
// 11051 https://boj.kr/11051
#include <bits/stdc++.h>
#define DIVIDER 10'007
using namespace std;

int n, k;
int dp[1001][1001];
int bi(int nn, int r)
{
    if (r == 0 || nn == r)
        return 1;

    int &ret = dp[nn][r];
    if (ret)
        return ret;

    return ret = bi(nn - 1, r - 1) % DIVIDER + bi(nn - 1, r) % DIVIDER;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    cout << bi(n, k) % DIVIDER;
}