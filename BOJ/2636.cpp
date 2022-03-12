#include <bits/stdc++.h>
using namespace std;
int board[101][101];
bool visited[101][101];
int n, m;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

bool isValid(int y, int x)
{
    return 1 <= y && y < n - 1 && 1 <= x && x < m - 1;
}

bool isValid2(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}

int remove(int y, int x, int marker)
{
    int rCnt = 0;
    visited[y][x] = true;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (isValid2(ny, nx) && board[ny][nx] == 1)
        {
            board[ny][nx] = marker;
            rCnt++;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (isValid2(ny, nx) && (board[ny][nx] == 0 || board[ny][nx] != marker) && !visited[ny][nx])
        {
            rCnt += remove(ny, nx, marker);
        }
    }
    return rCnt;
}

int total = 0, preTotal = 0;

int removeOnce(int marker)
{
    int cnt = remove(0, 0, marker);
    preTotal = total;
    total -= cnt;
    return cnt;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                total++;
        }

    int i = 0;
    while (total > 0)
    {
        removeOnce(i++ + 2);
        memset(visited, false, sizeof(visited));
    }
    cout << i << '\n'
         << preTotal;
}