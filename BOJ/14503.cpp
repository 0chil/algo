// 2022.04.17 23:44:27
// 14503 https://boj.kr/14503
#include <bits/stdc++.h>
using namespace std;
int n, m;
int board[51][51];
int cleaned[51][51];

bool isValid(int y, int x)
{
    return board[y][x] == 0;
}

bool isDirty(int y, int x)
{
    return isValid(y, x) && !cleaned[y][x];
}

const int ly[] = {0, -1, 0, 1};
const int lx[] = {-1, 0, 1, 0};
const int by[] = {1, 0, -1, 0};
const int bx[] = {0, -1, 0, 1};

class robot
{
public:
    int y, x, d, cleanCnt = 0;

    pair<int, int> getLeft()
    {
        return {y + ly[d], x + lx[d]};
    }

    pair<int, int> getBack()
    {
        return {y + by[d], x + bx[d]};
    }

    void turnLeft()
    {
        d = (d + 3) % 4;
    }

    void do1()
    {
        if (cleaned[y][x] == true)
            return;
        cleanCnt++;
        cleaned[y][x] = true;
    }

    bool do2a()
    {
        int i = 0;
        for (i = 0; i < 4; i++)
        {
            pair<int, int> left = getLeft();
            turnLeft();
            if (isDirty(left.first, left.second))
            {
                y = left.first;
                x = left.second;
                break;
            }
        }
        if (i == 4)
        {
            pair<int, int> back = getBack();
            if (isValid(back.first, back.second))
            {
                y = back.first;
                x = back.second;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

int dfs(robot &robot)
{
    robot.do1();

    if (robot.do2a())
    {
        return dfs(robot);
    }
    else
    {
        return robot.cleanCnt;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    robot robot({r, c, d});
    cout << dfs(robot);
}