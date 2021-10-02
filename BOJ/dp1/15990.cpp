// 2021.09.18 13:11:39
// 15990 https://boj.kr/15990
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009
long long dp[4][100002];

long long f(int before, int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    long long &ret = dp[before][n];
    if (ret != -1)
        return ret;
        
    ret = 0;
    for (int i = 1; i <= 3; i++)
    {
        if (before == i)
            continue;
        ret +=f(i, n - i) % MOD; //이부분에서 MOD-1+MOD-1+MOD-1 가 되면 초과! 맞나요?
    }
    return ret % MOD;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j <= 100001; j++)
        {
            dp[i][j] = -1;
        }
    }

    while (t--)
    {
        int n;
        cin >> n;

        cout << f(0, n) << '\n';
    }
}