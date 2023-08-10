// 2023.08.11 02:03:52
// 1026 https://boj.kr/1026
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;

    int a[51], b[51];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(a, a + n);
    sort(b, b + n, [](int a, int b) { return a > b; });

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += b[i] * a[i];
    }
    cout << total;
}