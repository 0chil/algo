// 2022.04.15 20:40:39
// 9655 https://boj.kr/9655
#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int f(int turn, int left)
{
    if (left < 0)
        return -987654321;
    if (left == 0)
        return !turn;
    int &ret = dp[turn][left];
    if (ret != -1)
        return ret;

    int getThree = f(!turn, left - 3);
    int getOne = f(!turn, left - 1);

    return ret = max(getThree, getOne);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;

    memset(dp, -1, sizeof(dp));

    cout << (f(0, n) == 0 ? "SK\n" : "CY\n");
    return 0;
}