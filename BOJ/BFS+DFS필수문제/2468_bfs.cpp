// 2021.10.03 19:53:31
// 2468 https://boj.kr/2468
#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int areas[101][101];
int visited[101][101];
int n;

class Area
{
public:
    int y, x;

    bool isValid()
    {
        return this->y >= 0 && this->y < n && this->x >= 0 && this->x < n;
    }

    bool isVisited()
    {
        return visited[y][x];
    }

    int getHeight()
    {
        return areas[y][x];
    }

    void setVisited()
    {
        visited[y][x] = 1;
    }
};

void bfs(int waterLevel, Area start)
{
    queue<Area> q;
    q.push(start);
    start.setVisited();

    while (!q.empty())
    {
        Area cur = q.front();
        q.pop();

        for (int next = 0; next < 4; next++)
        {
            Area nextNode = Area({cur.y + dy[next], cur.x + dx[next]});
            if (nextNode.isValid() && !nextNode.isVisited() && nextNode.getHeight() > waterLevel)
            {
                q.push(nextNode);
                nextNode.setVisited();
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int maxHeight = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> areas[i][j];
            maxHeight = max(maxHeight, areas[i][j]);
        }
    }
    int greatest = 0;
    for (int wl = 0; wl <= maxHeight; wl++)
    {
        int safeAreaCnt=0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Area cur = Area({i,j});
                if(!cur.isVisited() && cur.getHeight() > wl){
                    bfs(wl, cur);
                    safeAreaCnt++;
                }
            }
        }
        greatest = max(safeAreaCnt, greatest);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }
    }

    cout << greatest;
}