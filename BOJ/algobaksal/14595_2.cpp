// 2023.09.26 21:16:42
// 14595 https://boj.kr/14595
// Sweeping
#include <bits/stdc++.h>
using namespace std;

pair<int, int> actions[5001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        actions[i] = {x, y};
    }

    sort(actions, actions + m);

    int count = 0;
    int lastY = 0;
    for (int i = 0; i < m; i++)
    {
        pair<int, int> &current = actions[i];
        if (current.first > lastY)
        {
            count += current.first - lastY;
        }
        lastY = max(lastY, current.second);
    }
    count += n - lastY;

    cout << count;
}