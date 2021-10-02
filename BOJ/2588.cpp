// 2021.09.22 22:21:03
// 2588 https://boj.kr/2588
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    int res = a*b;
    for (int i = 10; b > 0; b/=i)
    {
        cout << a * (b % i) << '\n';
    }
    cout << res;
}