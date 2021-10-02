#include <bits/stdc++.h>
#define MAX_SIZE 101
using namespace std;

int dp[MAX_SIZE][MAX_SIZE], board[MAX_SIZE][MAX_SIZE];
int n;

int f(int y, int x)
{
    if (y == n - 1 && x == n - 1)
        return 1;
    if (y >= n || x >= n)
        return 0;
    if (dp[y][x] != -1)
        return dp[y][x];
    int jumpsize = board[y][x];
    return dp[y][x] = (f(y, x + jumpsize) || f(y + jumpsize, x));
}

int main()
{
    int c;
    cin >> c;
    while (c--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        if (f(0, 0)==1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}