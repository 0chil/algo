// 2022.03.16 23:21:00
// 2156 https://boj.kr/2156
#include <bits/stdc++.h>
using namespace std;

int n;
int vol[10001];
int dp[10001][2];

int f(int pos, int inRow)
{
    if (pos >= n)
        return 0;
    int &ret = dp[pos][inRow];
    if(ret != -1) return ret;

    int drink = INT_MIN;
    if (inRow < 2)
        drink = f(pos + 1, inRow + 1) + vol[pos];
    int skip = f(pos + 1, 0);
    return ret = max(drink, skip);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> vol[i];
    memset(dp, -1, sizeof(dp));

    cout << f(0, 0);
}