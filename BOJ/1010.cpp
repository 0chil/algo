// 2021.12.24 17:58:26
// 1010 https://boj.kr/1010
#include <bits/stdc++.h>
using namespace std;

int N, M;
int memo[31][31];

int f(int l, int r)
{
    if (l >= N)
        return 1;
    if (r >= M)
        return 0;
    int &ret = memo[l][r];
    if(ret != -1) return ret;

    int y = f(l + 1, r + 1);
    int n = f(l, r + 1);

    return ret = y + n;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        fill(&memo[0][0], &memo[30][31], -1);
        cin >> N >> M;
        cout << f(0, 0) << '\n';
    }
}