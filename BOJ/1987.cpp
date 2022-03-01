// 2022.03.01 22:44:45
// 1987 https://boj.kr/1987
#include <bits/stdc++.h>
using namespace std;

int r, c;

char board[21][21];
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};
bool visitAlphabet[26];

bool isValid(int y, int x)
{
    return 0 <= y && y < r && 0 <= x && x < c;
}

int dfs(int y, int x)
{
    int ret = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        char next = board[ny][nx];
        if (isValid(ny, nx) && !visitAlphabet[next - 'A'])
        {
            visitAlphabet[next - 'A'] = true;
            ret = max(ret, dfs(ny, nx) + 1);
            visitAlphabet[next - 'A'] = false;
        }
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
        }
    }

    visitAlphabet[board[0][0] - 'A'] = true;
    cout << dfs(0,0);
}