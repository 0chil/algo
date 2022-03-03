// 2022.03.03 23:22:03
// 9184 https://boj.kr/9184
#include <bits/stdc++.h>
using namespace std;
int dp[101][101][101];
int w(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);
    int &ret = dp[a + 50][b + 50][c + 50];
    if (ret != INT_MAX)
        return ret;
    else if (a < b && b < c)
        ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            for (int k = 0; k < 101; k++)
                dp[i][j][k] = INT_MAX;
    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }
}