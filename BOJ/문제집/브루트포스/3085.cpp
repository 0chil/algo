// 2021.10.17 22:23:47
// 3085 https://boj.kr/3085
#include <bits/stdc++.h>
using namespace std;

string board[51];
int n;
int dy[2] = {1, 0};
int dx[2] = {0, 1};

bool inRange(int y, int x)
{
    return 0 <= y && y < n && 0 <= x && x < n;
}

int maxInRowUp(int y, int x, char c)
{
    if (!inRange(y, x))
        return 0;
    if (c != board[y][x])
        return 0;
    return maxInRowUp(y - 1, x, c) + 1;
}

int maxInRowDown(int y, int x, char c)
{
    if (!inRange(y, x))
        return 0;
    if (c != board[y][x])
        return 0;
    return maxInRowDown(y + 1, x, c) + 1;
}
int maxInColLeft(int y, int x, char c)
{
    if (!inRange(y, x))
        return 0;
    if (c != board[y][x])
        return 0;
    return maxInColLeft(y, x - 1, c) + 1;
}
int maxInColRight(int y, int x, char c)
{
    if (!inRange(y, x))
        return 0;
    if (c != board[y][x])
        return 0;
    return maxInColRight(y, x + 1, c) + 1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char &one = board[i][j];
            int toCompare[2] = {};
            toCompare[0] = maxInRowUp(i - 1, j, one) + maxInRowDown(i + 1, j, one) + 1;
            toCompare[1] = maxInColLeft(i, j - 1, one) + maxInColRight(i, j + 1, one) + 1;
            for (int compareI = 0; compareI < 2; compareI++)
                maximum = max(maximum, toCompare[compareI]);

            for (int other = 0; other < 2; other++)
            {
                int othery = i + dy[other];
                int otherx = j + dx[other];
                if (inRange(othery, otherx))
                {
                    char &otherone = board[othery][otherx];
                    if (one == otherone)
                        continue;
                    swap(one, otherone);
                    int toCompare[4] = {};
                    toCompare[0] = maxInRowUp(i - 1, j, one) + maxInRowDown(i + 1, j, one) + 1;
                    toCompare[1] = maxInColLeft(i, j - 1, one) + maxInColRight(i, j + 1, one) + 1;
                    toCompare[2] = maxInRowUp(othery - 1, otherx, otherone) + maxInRowDown(othery + 1, otherx, otherone) + 1;
                    toCompare[3] = maxInColLeft(othery, otherx - 1, otherone) + maxInColRight(othery, otherx + 1, otherone) + 1;

                    for (int compareI = 0; compareI < 4; compareI++)
                        maximum = max(maximum, toCompare[compareI]);

                    swap(one, otherone);
                }
            }
        }
    }

    cout << maximum;
}