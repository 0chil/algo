// 2021.10.17 23:18:35
// 1476 https://boj.kr/1476
#include <bits/stdc++.h>
using namespace std;

int adjust(int year, int boundary){
    if(year <=0) return year = boundary;
    return year;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int e, s, m;

    cin >> e >> s >> m;

    int year = 1;
    while (e != 1 || s != 1 || m != 1)
    {
        e = adjust(e - 1,15);
        s = adjust(s - 1,28);
        m = adjust(m - 1,19);
        year++;
    }
    cout << year;
}