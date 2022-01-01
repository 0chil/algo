// 2021.12.30 13:24:33
// 7576 https://boj.kr/7576
#include <bits/stdc++.h>

#define RIPE 1
#define UNRIPE 0
#define EMPTY -1

using namespace std;
const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

int box[1001][1001];
int n, m;

class Loc
{
public:
    int y, x, day = 0;

    void ripen()
    {
        box[y][x] = RIPE;
    }

    bool isValid()
    {
        return 0 <= y && y < n && 0 <= x && x < m && box[y][x] == UNRIPE;
    }
};

int bfs(queue<Loc> q)
{
    int estDay = 0;
    while (!q.empty())
    {
        Loc cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Loc next = {cur.y + dy[i], cur.x + dx[i], cur.day + 1};
            if (next.isValid())
            {
                q.push(next);
                next.ripen();
                estDay = max(estDay, next.day);
            }
        }
    }
    return estDay;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> m >> n;
    queue<Loc> ripes;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> box[i][j];
            if (box[i][j] == RIPE)
                ripes.push({i, j});
        }
    int ret = bfs(ripes);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (box[i][j] == UNRIPE){
                ret = -1;
                break;
            }
    cout << ret;
}