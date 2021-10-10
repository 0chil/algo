// 2021.10.10 13:56:53
// 17404 https://boj.kr/17404
#include <bits/stdc++.h>
using namespace std;
#define R 0
#define G 1
#define B 2
const int colors[3] = {R, G, B};
vector<vector<int>> cost;
int n;
int dp[1001][3][3];
int f(int pos, int c, int first)
{
    if (pos >= n)
        return 0;
    int &ret = dp[pos][c][first];
    if (ret)
        return ret;
    ret = INT_MAX;
    for (auto &color : colors)
    {
        if (pos == n - 1 && first == color)
            continue;
        if (c == color)
            continue;
        int next = f(pos + 1, color, first) + cost[pos][color];
        ret = min(ret, next);
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int input;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> _cost;
        for (auto &color : colors)
        {
            cin >> input;
            _cost.push_back(input);
        }
        cost.push_back(_cost);
    }

    int least = INT_MAX;
    // 첫번째 색 결정 + 2번째부터 ~ 마지막까지
    for (auto &color : colors)
    {
        least = min(f(1, color, color) + cost[0][color], least);
    }
    cout << least;
}