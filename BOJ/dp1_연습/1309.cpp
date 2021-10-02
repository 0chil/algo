// 2021.09.18 22:40:32
// 1309 https://boj.kr/1309
#include <bits/stdc++.h>
using namespace std;
#define MOD 9901
int dp[3][100001];

int f(int lion, int n)
{
    if (n == 1)
        return 1;
    int &ret = dp[lion][n];
    if (ret)
        return ret;
    ret = 0;
    for (int next_lion = 0; next_lion < 3; next_lion++)
    {
        if (lion && lion == next_lion)
            continue;
        ret = (ret % MOD + f(next_lion, n - 1) % MOD) % MOD;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum = (sum % MOD + f(i, n) % MOD) % MOD;
    }
    cout << sum;
}