#include <bits/stdc++.h>

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

int board[51][51];
bool visited[51][51];
int m, n, k;

class Loc
{
public:
    int y, x;

    bool isVisited()
    {
        return visited[y][x];
    }

    void visit()
    {
        visited[y][x] = true;
    }

    bool isValid()
    {
        return 0 <= y && y < n && 0 <= x && x < m && board[y][x] == 1;
    }
};

void bfs(int y, int x)
{
    queue<Loc> q;
    q.push(Loc({y, x}));
    while (!q.empty())
    {
        Loc cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Loc next = Loc({cur.y + dy[i], cur.x + dx[i]});
            if (next.isValid() && !next.isVisited())
            {
                next.visit();
                q.push(next);
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n >> k;
        memset(board, 0, sizeof(board));
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < k; i++)
        {
            int y, x;
            cin >> x >> y;
            board[y][x] = 1;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && board[i][j])
                {
                    bfs(i, j);
                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }
}