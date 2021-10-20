// 2021.10.20 22:55:00
// 1743 https://boj.kr/1743
#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int n, m, k;
bool hallway[101][101], visited[101][101];

class Location
{
public:
    int y, x;

    bool isVisited()
    {
        return visited[y][x];
    }

    bool isValid()
    {
        return 0 <= y && y < n && 0 <= x && x < m;
    }

    bool isTrash()
    {
        return hallway[y][x];
    }
};

int dfs(Location currentNode)
{
    visited[currentNode.y][currentNode.x] = true;
    int trashSize = 1;
    for (int next = 0; next < 4; next++)
    {
        Location nextNode = {currentNode.y + dy[next], currentNode.x + dx[next]};
        if (nextNode.isValid() && !nextNode.isVisited() && nextNode.isTrash())
        {
            trashSize += dfs(nextNode);
        }
    }
    return trashSize;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int y, x;
        cin >> y >> x;
        hallway[y-1][x-1] = true;
    }

    int maxTrashSize = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            Location start = {i, j};
            if (!start.isVisited() && start.isTrash())
            {
                maxTrashSize = max(maxTrashSize, dfs(start));
            }
        }
    }
    cout << maxTrashSize;
}