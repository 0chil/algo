#include <bits/stdc++.h>
using namespace std;
int n;
int cache[100][100], triangle[100][100];

int f(int y, int x)
{
    int &ret = cache[y][x];
    if (ret != -1)
        return ret;
    if (y == n - 1)
        return triangle[y][x];
    return ret = max(f(y + 1, x), f(y + 1, x + 1)) + triangle[y][x];
}

int main()
{
    int c;
    cin >> c;
    while (c--)
    {
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                cache[i][j] = -1;
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i+1; j++)
                cin >> triangle[i][j];
        cout << f(0, 0) << '\n';
    }
}