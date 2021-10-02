// 2021.09.25 22:43:38
// 2225 https://boj.kr/2225
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000

long long dp[201][201];

long long f(int number, int cnt)
{
    if (number == 0 && cnt == 0)
        return 1;
    if (cnt == 0)
        return 0;
    long long &ret = dp[number][cnt];
    if (ret)
        return ret;
    ret = 0;
    for (int i = 0; i <= number; i++)
    {
        int pick_i = f(number - i, cnt - 1);
        ret += pick_i % MOD;
    }
    return ret = ret % MOD;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    cout << f(n, k);
}