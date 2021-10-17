// 2021.10.06 22:46:45
// 14503 https://boj.kr/14503
#include <bits/stdc++.h>
using namespace std;

const int lefty[4] = {0, -1, 0, 1};
const int leftx[4] = {-1, 0, 1, 0};

int n, m, clearedCnt = 0;
int place[51][51];

class Robot
{
public:
    int y, x, d;

    void clear()
    {
        if (place[y][x] == 0)
        {
            place[y][x] = 2;
            clearedCnt++;
        }
    }

    bool goBackward()
    {
        int backwardDir = (d + 3) % 4;
        int backwardy = y + lefty[backwardDir];
        int backwardx = x + leftx[backwardDir];

        if (place[backwardy][backwardx] == 1)
            return false;

        this->y = backwardy;
        this->x = backwardx;
        return true;
    }
};

void dfs(Robot currentNode, int failedCnt)
{
    currentNode.clear();
    if (failedCnt == 4)
    {
        if (currentNode.goBackward())
        {
            dfs(currentNode, 0);
            return;
        }
        else
        {
            return;
        }
    }
    int leftDir = (currentNode.d + 3) % 4;
    Robot leftNode = Robot({currentNode.y + lefty[currentNode.d], currentNode.x + leftx[currentNode.d], leftDir});
    if (place[leftNode.y][leftNode.x] == 0)
    {
        dfs(leftNode, 0);
        return;
    }
    else if (place[leftNode.y][leftNode.x] > 0)
    {
        currentNode.d = leftNode.d;
        dfs(currentNode, failedCnt + 1);
        return;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    Robot start;
    cin >> n >> m >> start.y >> start.x >> start.d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> place[i][j];
        }
    }

    dfs(start, 0);

    cout << clearedCnt;
}

/*
4 5
1 1 0
1 1 1 1 1
1 0 0 0 1
1 0 1 1 1
1 1 1 1 1
*/