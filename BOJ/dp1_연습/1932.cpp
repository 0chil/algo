// 2021.09.18 23:49:24
// 1932 https://boj.kr/1932
#include <bits/stdc++.h>
using namespace std;

int dp[501][501];
vector<vector<int>> triangle;

int f(int y, int x)
{
    if (y >= triangle.size() || x > y)
        return 0;
    int &ret = dp[y][x];
    if (ret != -1)
        return ret;
    int left = f(y + 1, x) + triangle[y][x];
    int right = f(y + 1, x + 1) + triangle[y][x];
    return ret  = max(left,right);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, input;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j <= i; j++)
        {
            cin >> input;
            row.push_back(input);
        }
        triangle.push_back(row);
    }

    cout << f(0,0);
}