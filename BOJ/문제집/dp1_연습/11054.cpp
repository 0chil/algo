// 2021.10.08 22:51:49
// 11054 https://boj.kr/11054
#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int dp[1001][2];
int f(int pos, int increasing)
{
    if (pos >= a.size())
        return 0;
    int &ret = dp[pos][increasing];
    if (ret)
        return ret;
    ret = 1;

    if (increasing)
    {
        for (int next = pos + 1; next < a.size(); next++)
        {
            if (a[pos] < a[next])
            {
                int go = f(next, 1) + 1;
                int stop = f(next, 0) + 1;
                ret = max(max(ret, go), stop);
            }
        }
    }
    else
    {
        for (int next = pos + 1; next < a.size(); next++)
        {
            if (a[pos] > a[next])
            {
                ret = max(ret, f(next, 0) + 1);
            }
        }
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, input;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        a.push_back(input);
    }

    int greatest = 0;
    for (int i = 0; i < n; i++)
    {
        greatest = max(max(greatest, f(i, 1)), f(i, 0));
    }

    cout << greatest;
}