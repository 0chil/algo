// 2021.10.20 21:59:20
// 7562 https://boj.kr/7562
#include <bits/stdc++.h>
using namespace std;
const int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

int visited[301][301];
int l, objY, objX;
class Move
{
public:
    int toY, toX, depth;
    bool isObjective()
    {
        return toY == objY && toX == objX;
    }

    bool isValid()
    {
        return 0 <= toY && toY < l && 0 <= toX && toX < l;
    }

    bool isVisited()
    {
        return visited[toY][toX];
    }
};

void bfs(Move start)
{
    queue<Move> q;
    q.push(start);

    while (!q.empty())
    {
        Move cur = q.front();
        q.pop();
        if (cur.isObjective())
        {
            cout << cur.depth << '\n';
            return;
        }

        for (int next = 0; next < 8; next++)
        {
            Move nextMove = {cur.toY + dy[next], cur.toX + dx[next], cur.depth + 1};
            if (nextMove.isValid() && !nextMove.isVisited())
            {
                q.push(nextMove);
                visited[nextMove.toY][nextMove.toX] = true;
            }
        }
    }
}

void clearVisited()
{
    for (int i = 0; i < 301; i++)
    {
        for (int j = 0; j < 301; j++)
        {
            visited[i][j] = 0;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int startY, startX;
        cin >> l >> startY >> startX >> objY >> objX;
        Move start = {startY, startX, 0};
        bfs(start);
        clearVisited();
    }
}