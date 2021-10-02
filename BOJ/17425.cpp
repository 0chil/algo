// 2021.07.12 23:11:02
// 17425 http://boj.kr/17425
#include <bits/stdc++.h>
using namespace std;

int dp[1000000];

int f(int num)
{
    int &ret = dp[num];
    if (dp[num] != -1)
        return ret;
}

int main()
{
    int t;
    cin >> t;
    for (auto &num : dp)
        num = -1;
    while (t--)
    {
        int n;
        cin >> n;
        cout << f(n) << '\n';
    }
}