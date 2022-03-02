// 2022.03.02 17:43:48
// 2631 https://boj.kr/2631
#include <bits/stdc++.h>
using namespace std;

int n;
int children[201];
int dp[201];
int f(int pos)
{
    int &ret = dp[pos];
    if (ret)
        return ret;
    ret = 1;
    for (int i = pos + 1; i < n; i++)
    {
        if (children[pos] < children[i])
            ret = max(ret, f(i) + 1);
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> children[i];

    int ret = 1;
    for (int i = 0; i < n; i++)
    {
        ret = max(ret, f(i));
    }
    cout << n - ret;
}