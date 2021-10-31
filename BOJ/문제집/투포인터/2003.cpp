// 2021.10.31 10:51:05
// 2003 https://boj.kr/2003
#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n, m;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        a.push_back(input);
    }
    int cnt = 0;
    int i = 0, j = i;
    while (true)
    {
        if (j >= n)
            break;
        int ps = 0;
        for (int it = i; it <= j; it++)
        {
            ps += a[it];
        }
        if (ps < m)
        {
            j++;
        }
        else if (ps > m)
        {
            i++;
        }
        else
        {
            cnt++;
            i++;
            j++;
        }
    }

    cout << cnt;
}