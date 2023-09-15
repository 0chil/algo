// 2023.09.16 03:32:31
// 26215 https://boj.kr/26215
#include <bits/stdc++.h>
using namespace std;

int snow[101];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> snow[i];
    }
    sort(snow + 1, snow + n + 1);

    int elapsed = 0;
    for (int i = 1; i < n; i++)
    {
        while (snow[i])
        {
            snow[i]--;
            snow[n]--;
            elapsed++;
            sort(snow + i, snow + n + 1);
        }
    }
    elapsed += snow[n];
    if (elapsed > 1440)
    {
        cout << -1;
        return 0;
    }
    cout << elapsed;

    // 3 3 3
    // 2 2 3
    // 1 2 2
    // 0 1 2
    // 0 0 1
    // 0 0 0
}