#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> answer;
bool visited[501][501][4];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

bool isInRange(int y, int x, vector<string> &grid)
{
    return 0 <= y && y < grid.size() && 0 <= x && x < grid[0].size();
}

void adjustCord(int &y, int &x, vector<string> &grid)
{
    if (y < 0)
        y = grid.size() - 1;
    else if (y >= grid.size())
        y = 0;

    if (x < 0)
        x = grid[0].size() - 1;
    else if (x >= grid[0].size())
        x = 0;
}

void dfs(int y, int x, int dir, int depth, vector<string> &grid)
{
    visited[y][x][dir] = true;

    int nd;
    switch (grid[y][x])
    {
    case 'S':
        nd = dir;
        break;
    case 'L':
        nd = (dir + 3) % 4;
        break;
    case 'R':
        nd = (dir + 1) % 4;
        break;
    }
    int ny = y + dy[nd];
    int nx = x + dx[nd];
    adjustCord(ny, nx, grid);
    if (visited[ny][nx][nd])
    {
        answer.push_back(depth + 1);
    }
    else
    {
        dfs(ny, nx, nd, depth + 1, grid);
    }
}

vector<int> solution(vector<string> grid)
{

    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            for (int d = 0; d < 4; d++)
            {
                if (!visited[i][j][d])
                {
                    dfs(i, j, d, 0, grid);
                }
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}