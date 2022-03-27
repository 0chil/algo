// 2022.03.27 20:13:21
// 10844 https://boj.kr/10844
#include <bits/stdc++.h>
#define DIVIDER 1'000'000'000
using namespace std;

int n;
int dp[101][10];
int f(int ni, int cur)
{
    if (cur < 0 || cur > 9)
        return 0;
    if (ni == n - 1)
        return 1;
    int &ret = dp[ni][cur];
    if (ret != -1)
        return ret;

    int up = f(ni + 1, cur + 1) % DIVIDER;
    int down = f(ni + 1, cur - 1) % DIVIDER;
    return ret = (up + down) % DIVIDER;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    memset(dp, -1, sizeof(dp));

    cin >> n;
    int ans = 0;
    for (int i = 1; i <= 9; i++)
        ans = (ans + f(0, i)) % DIVIDER;
    cout << ans;
}