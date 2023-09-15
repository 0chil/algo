// 2023.09.16 02:31:46
// 2775 https://boj.kr/2775
#include <bits/stdc++.h>
using namespace std;

int apartment[15][15];

// 0+1 0+1+2 0+1+2+3

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    for (int i = 1; i <= 14; i++)
    {
        apartment[0][i] = apartment[0][i - 1] + i;
    }
    for (int i = 1; i <= 14; i++)
    {
        for (int j = 1; j <= 14; j++)
        {
            apartment[i][j] = apartment[i][j - 1] + apartment[i - 1][j];
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int k, n;
        cin >> k >> n;
        cout << apartment[k][n] - apartment[k][n - 1] << '\n';
    }
}