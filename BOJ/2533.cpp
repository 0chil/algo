// 2022.03.03 18:34:59
// 2533 https://boj.kr/2533
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rel = vector<vector<int>>(1000001, vector<int>());
int dp[1000001][2];
int n;
int f(int pos, int bpos, bool before)
{
    int &ret = dp[pos][before];
    if (ret != -1)
        return ret;
    ret = 0;
    for (int next : rel[pos])
    {
        if (next == bpos)
            continue;
        if (before == true)
        {
            int earlyMe = f(next, pos, true) + 1;
            int notMe = f(next, pos, false);
            ret += min(earlyMe, notMe);
        }
        else
        {
            int earlyMe = f(next, pos, true) + 1;
            ret += earlyMe;
        }
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        rel[a].push_back(b);
        rel[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    cout << min(f(1, 0, false), f(1, 0, true) + 1) << endl;
}