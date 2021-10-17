// 2021.09.18 22:55:18
// 11057 https://boj.kr/11057
#include <bits/stdc++.h>
using namespace std;
#define MOD 10007
int dp[1001][10];

int f(int n, int digit)
{
    if (n == 1) // n부터 시작했음.
        return 1;
    int &ret = dp[n][digit];
    if (ret)
        return ret;
    ret = 0;
    for (int next_digit = 0; next_digit <= digit; next_digit++)
    {
        ret = (ret % MOD + f(n - 1, next_digit) % MOD) % MOD;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int sum=0;
    for (int next_digit = 0; next_digit <= 9; next_digit++)
    {
        sum = (sum % MOD + f(n, next_digit) % MOD) % MOD;
    }
    cout << sum % MOD;
}