// 2021.10.01 13:20:28
// 2178 https://boj.kr/2178
#include <bits/stdc++.h>
using namespace std;
int n, m;
int maze[101][101];
int visited[101][101];
const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

class Node
{
public:
    Node(int y, int x, int depth)
    {
        this->y = y;
        this->x = x;
        this->depth = depth;
    }
    int y;
    int x;
    int depth;
};

bool inRange(Node node)
{
    return node.y >= 1 && node.x >= 1 && node.y <= n && node.x <= m;
}

int bfs(int starty, int startx)
{
    int least = 987654321;

    queue<Node> q;
    q.push(Node(starty, startx, 1));

    while (!q.empty())
    {
        Node currentNode = q.front();
        q.pop();
        for (int next = 0; next < 4; next++)
        {
            Node nextNode = Node(currentNode.y + dy[next], currentNode.x + dx[next], currentNode.depth + 1);
            if (nextNode.y == n && nextNode.x == m)
            {
                least = min(least, nextNode.depth);
                break;
            }
            else if (inRange(nextNode) && !visited[nextNode.y][nextNode.x] && maze[nextNode.y][nextNode.x])
            {
                q.push(nextNode);
                visited[nextNode.y][nextNode.x] = 1;
            }
        }
    }
    return least;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            maze[i][j] = (s[j - 1] == '1');
        }
    }

    cout << bfs(1, 1);
}