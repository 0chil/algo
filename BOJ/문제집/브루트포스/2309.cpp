// 2021.10.17 22:14:16
// 2309 https://boj.kr/2309
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int heights[9];
    int total = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> heights[i];
        total += heights[i];
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (total - heights[i] - heights[j] == 100)
            {
                heights[i] = heights[j] = 0;
                i = 10;
                break;
            }
        }
    }

    sort(heights, heights + 9);

    for (int i = 2; i < 9; i++)
    {
        cout << heights[i] << '\n';
    }
}