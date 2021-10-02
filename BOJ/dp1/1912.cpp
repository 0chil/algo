// 2021.09.25 22:00:13
// 1912 https://boj.kr/1912
#include <bits/stdc++.h>
using namespace std;

vector<int> s;
int dp[100001];
int f(int pos)
{
    if (pos >= s.size())
        return 0;
    int &ret = dp[pos];
    if (ret != -987654321)
        return ret;
    int addNext = f(pos + 1) + s[pos];
    int stop = s[pos];
    return ret = max(addNext, stop);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s.push_back(temp);
        dp[i] = -987654321;
    }

    int best = -987654321;
    for (int i = 0; i < n; i++)
    {
        best = max(best, f(i));
    }
    cout << best;
}