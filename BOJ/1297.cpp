// 2021.11.26 16:49:20
// 1297 https://boj.kr/1297
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    double d, h, w;
    cin >> d >> h >> w;

    double x = sqrt(d * d / (h * h + w * w));

    cout << floor(h * x) << ' ' << floor(w * x);
}