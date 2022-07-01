// 2022.01.13 21:49:11
// 14501 https://boj.kr/14501
#include <bits/stdc++.h>
using namespace std;

int n;
int t[16];
int p[16];
int dp[16];
int f(int day)
{
    if (day >= n)
        return 0;
    int &ret = dp[day];
    if (ret != -1)
        return ret;
    if (day + t[day] > n)
        return ret = f(day + 1);
    int take = f(day + t[day]) + p[day];
    int skip = f(day + 1);
    return ret = max(take, skip);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> p[i];
    }
    fill(dp, dp + 16, -1);

    cout << f(0);
}