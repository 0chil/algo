#include <bits/stdc++.h>
using namespace std;
int n, m;
int board[101][101];
int marks[101][101];
bool visited[101][101];

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

queue<pair<int, int>> rq;

bool isValid(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < m;
}

void mark(int y, int x)
{
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (isValid(ny, nx) && board[ny][nx] != 0 && marks[ny][nx] < 2)
        {
            marks[ny][nx]++;
            if (marks[ny][nx] >= 2)
                rq.push({ny, nx});
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (isValid(ny, nx) && !visited[ny][nx] && board[ny][nx] == 0)
        {
            mark(ny, nx);
        }
    }
}

void processQueue()
{
    while (!rq.empty())
    {
        pair<int, int> next = rq.front();
        board[next.first][next.second] = 0;
        rq.pop();
    }
}

int main()
{
    int total = 0;
    int time = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
                ++total;
        }
    }

    while (total)
    {
        mark(0, 0);
        total -= rq.size();
        processQueue();
        memset(visited, false, sizeof(visited));
        memset(marks, 0, sizeof(marks));
        time++;
    }
    cout << time;
}