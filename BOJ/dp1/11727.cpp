// 2021.09.18 12:34:53
// 11727 https://boj.kr/11727
#include <bits/stdc++.h>
using namespace std;

int dp[1001];
int f(int space)
{
    int &ret = dp[space];
    if (ret != -1)
        return ret;
    if (space < 0)
        return 0;
    if (space == 0)
        return 1;
    int sum = 0;
    sum += f(space - 1);
    sum += f(space - 2) * 2;
    return ret = sum % 10007;
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