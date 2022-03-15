// 2022.03.15 15:39:56
// 2206 https://boj.kr/2206
#include <bits/stdc++.h>
using namespace std;
char board[1001][1001];
bool visited[1001][1001][2];
int n, m;

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

class Node
{
public:
    int y, x, breakable = true, depth;

    bool isValid()
    {
        return 0 <= y && y < n && 0 <= x && x < m;
    }

    bool isVisited()
    {
        return visited[y][x][breakable];
    }

    void visit()
    {
        visited[y][x][breakable] = true;
    }

    // void print()
    // {
    //     cout << "(" << y << ", " << x << ", able = " << breakable << ", depth = " << depth << ")\n";
    // }
};

int bfs(Node start)
{
    queue<Node> q;
    q.push(start);
    start.visit();
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        // cur.print();
        if (cur.y == n - 1 && cur.x == m - 1)
            return cur.depth;
        for (int i = 0; i < 4; i++)
        {
            Node next = {cur.y + dy[i], cur.x + dx[i], cur.breakable, cur.depth + 1};
            Node breakNext = {cur.y + dy[i], cur.x + dx[i], false, cur.depth + 1};
            if (next.isValid() && !next.isVisited())
            {
                if (board[next.y][next.x] == 1 && cur.breakable)
                {
                    q.push({next.y, next.x, false, cur.depth + 1});
                }
                if (board[next.y][next.x] == 0)
                {
                    q.push(next);
                }
                q.back().visit();
            }
        }
    }
    return -1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            board[i][j] = (c == '1');
        }
    }

    cout << bfs({0, 0, true, 1});
}