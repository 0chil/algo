// 2022.02.24 18:21:11
// 1520 https://boj.kr/1520
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int n, m;
int maze[501][501];
int dp[501][501];
bool invalid(int y, int x)
{
    return y < 0 || y >= n || x < 0 || x >= m;
}

int dfs(int y, int x)
{
    if (y == n - 1 && x == m - 1)
        return 1;

    int &ret = dp[y][x];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (invalid(ny, nx) || maze[ny][nx] >= maze[y][x])
            continue;
        ret += dfs(ny, nx);
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    memset(dp, -1, sizeof(int) * 501 * 501);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
        }
    }

    cout << dfs(0, 0);
}