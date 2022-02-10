// 2022.02.11 01:35:09
// 1699 https://boj.kr/1699
#include <bits/stdc++.h>
using namespace std;

int dp[100001];

int f(int left)
{
    if (left <= 3)
        return left;
    int &ret = dp[left];
    if (ret)
        return ret;
    ret = INT_MAX;
    for (int i = 1; i * i <= left; i++)
        ret = min(ret, f(left - i * i) + 1);
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << f(n);
}