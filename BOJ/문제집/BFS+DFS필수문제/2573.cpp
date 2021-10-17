// 2021.10.03 22:40:49
// 2573 https://boj.kr/2573
#include <bits/stdc++.h>
using namespace std;
const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};
int n, m;
int ice[301][301];
int visited[301][301];
int icebergCnt;

class Iceberg
{
public:
    int y, x;
    void setVisited()
    {
        visited[y][x] = 1;
    }
    bool isVisited()
    {
        return visited[y][x];
    }
    bool isValid()
    {
        return this->getHeight() > 0;
    }
    int getHeight()
    {
        return ice[y][x];
    }
};

void resetVisited()
{
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            visited[i][j] = 0;
        }
    }
}

void printMap()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ice[i][j] > 0)
                cout << ice[i][j] << ' ';
            else
                cout << "0 ";
        }
        cout << endl;
    }
    cout << endl;
}

// 방문한 빙산 개수 출력
int bfs(Iceberg start)
{
    int visitCnt = 1;
    queue<Iceberg> q;
    q.push(start);
    start.setVisited();

    while (!q.empty())
    {
        Iceberg cur = q.front();
        q.pop();
        int seaCnt = 0;
        for (int next = 0; next < 4; next++)
        {
            Iceberg nextNode = Iceberg({cur.y + dy[next], cur.x + dx[next]});
            if (nextNode.isVisited())
                continue;
            if (!nextNode.isValid())
            {
                seaCnt++;
                continue;
            }
            if (nextNode.isValid())
            {
                q.push(nextNode);
                nextNode.setVisited();
                visitCnt++;
            }
        }
        if ((ice[cur.y][cur.x] -= seaCnt) <= 0)
        {
            icebergCnt--;
        }
    }
    return visitCnt;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int maxYear = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> ice[i][j];
            if (ice[i][j])
                icebergCnt++;
            maxYear = max(maxYear, ice[i][j]);
        }
    }
    int years = 0;
    for (;; years++)
    {
        int iceBergbefore = icebergCnt;
        int visitCnt = 0;

        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                Iceberg cur = Iceberg({i, j});
                if (!cur.isVisited() && cur.isValid())
                {
                    visitCnt = bfs(cur);
                    i = n;
                    break;
                }
            }
        }
        if (iceBergbefore == 0 && visitCnt == 0)
        {
            break;
        }

        if (iceBergbefore != visitCnt)
        {
            cout << years;
            return 0;
        }
        resetVisited();
    }
    cout << 0;
}