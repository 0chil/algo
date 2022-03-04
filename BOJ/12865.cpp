// 2022.03.04 13:43:30
// 12865 https://boj.kr/12865
#include <bits/stdc++.h>
using namespace std;

vector<int> v, w;
int dp[101][100001];
int n, k;
int f(int vi, int kLeft)
{
    if (kLeft < 0)
        return -987654321;
    if (vi >= n)
        return 0;
    int &ret = dp[vi][kLeft];
    if (ret != -1)
        return ret;
    int takeThis = f(vi + 1, kLeft - w[vi]) + v[vi];
    int leftThis = f(vi + 1, kLeft);

    return ret = max(takeThis, leftThis);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int wt, vt;
        cin >> wt >> vt;
        v.push_back(vt);
        w.push_back(wt);
    }
    memset(dp, -1, sizeof(dp));

    cout << f(0, k);
}