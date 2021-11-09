// 2021.11.09 11:58:04
// 1261 https://boj.kr/1261
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};
int n, m;
char space[101][101];
bool visited[101][101];

class Node
{
public:
    int y, x, depth;

    bool isInRange()
    {
        return 0 <= y && y < n && 0 <= x && x < m;
    }

    bool isVisited()
    {
        return visited[y][x];
    }

    void visit()
    {
        visited[y][x] = true;
    }
};

int bfs()
{
    deque<Node> q;
    q.push_back({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop_front();
        
        if (cur.y == n - 1 && cur.x == m - 1)
        {
            return cur.depth;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            Node nextNode = {ny, nx, cur.depth};
            if (nextNode.isInRange() && !nextNode.isVisited())
            {
                if (space[ny][nx] == '1')
                {
                    nextNode.depth++;
                    q.push_back(nextNode);
                }
                else{
                    q.push_front(nextNode);
                }
                nextNode.visit();
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> space[i];
    }

    cout << bfs();
}