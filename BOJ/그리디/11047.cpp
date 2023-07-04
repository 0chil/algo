// 2023.07.04 09:18:27
// 11047 https://boj.kr/11047
#include <bits/stdc++.h>
using namespace std;

int value[11];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int used = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int count = k / value[i];
        used += count;
        k -= count * value[i];
    }
    cout << used;
}