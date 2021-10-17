// 2021.10.03 22:26:25
// 2468 https://boj.kr/2468
#include <bits/stdc++.h>
using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int n;
int height[101][101];
int visited[101][101];
int waterLevel;
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
        return height[y][x];
    }

    void setVisited()
    {
        visited[y][x] = 1;
    }
};

void dfs(Area currentNode)
{
    currentNode.setVisited();

    for (int next = 0; next < 4; next++)
    {
        Area nextNode = Area({currentNode.y + dy[next], currentNode.x + dx[next]});
        if (nextNode.isValid() && !nextNode.isVisited() && nextNode.getHeight() > waterLevel)
        {
            dfs(nextNode);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int maxWaterLevel = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> height[i][j];
            maxWaterLevel = max(maxWaterLevel, height[i][j]);
        }
    }
    int greatest = 0;
    for (; waterLevel <= maxWaterLevel; waterLevel++)
    {
        int safeAreaCnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Area currentNode = Area({i, j});
                if (!currentNode.isVisited() && currentNode.getHeight() > waterLevel)
                {
                    dfs(currentNode);
                    safeAreaCnt++;
                }
            }
        }
        greatest = max(greatest,safeAreaCnt);
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