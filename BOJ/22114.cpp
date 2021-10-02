// 2021.07.19 22:10:43
// 22114 http://boj.kr/22114

#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int l[100100];
int dp[100100][1];
int f(int pos, int jumped)
{
    if(pos == n-1) return 1;
    if (pos >= n)
        return 0;
    int &ret = dp[pos][jumped];
    if (ret != -1)
        return ret;
    if (l[pos] > k)
    {
        if (!jumped)
            return ret = f(pos + 1, 1) + 1;
        else
            return ret = 0;
    }
    return ret = f(pos + 1, jumped) + 1;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> l[i];
    }
    for (auto &arr : dp)
        for (auto &num : arr)
            num = -1;
    int maxJump = 0;
    for (int i = 0; i < n; i++)
    {
        maxJump = max(maxJump, f(i, 0));
    }
    cout << maxJump << '\n';
}