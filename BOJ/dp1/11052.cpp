// 2021.09.18 12:44:01
// 11052 https://boj.kr/11052
#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int dp[1001];

int f(int card_left)
{
    int &ret = dp[card_left];
    if (card_left < 0)
        return -987654321;
    if (ret != -1)
        return ret;
    if (card_left == 0)
        return 0;
    int cost = 0;
    for (int i = 1; i < p.size(); i++)
    {
        cost = max(cost, f(card_left - i) + p[i]);
    }
    return ret = cost;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    p.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int pi;
        cin >> pi;
        p.push_back(pi);
    }

    cout << f(n);
}