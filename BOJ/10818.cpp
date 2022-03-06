// 2022.03.06 23:44:28
// 10818 https://boj.kr/10818
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, ma = -1000000, mi = 1000000;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        ma = max(ma, tmp);
        mi = min(mi, tmp);
    }
    cout << mi << ' ' << ma << '\n';
}