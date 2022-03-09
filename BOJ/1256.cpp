// 2022.03.07 15:32:03
// 1256 https://boj.kr/1256
#include <bits/stdc++.h>
#define BOUNDARY 1'000'000'001
using namespace std;

int n, m;
int k;
int dp[101][101];

int f(int aLeft, int zLeft)
{
    if (aLeft == 0 || zLeft == 0)
        return 1;
    int &ret = dp[aLeft][zLeft];
    if (ret != -1)
        return ret;
    int useA = f(aLeft - 1, zLeft);
    int useB = f(aLeft, zLeft - 1);
    if (useA + useB >= BOUNDARY)
        return ret = BOUNDARY;
    return ret = useA + useB;
}

void d(int aLeft, int zLeft, int kLeft)
{
    if (aLeft == 0)
    {
        for (int i = 0; i < zLeft; i++)
            cout << 'z';
        return;
    }
    if (zLeft == 0)
    {
        for (int i = 0; i < aLeft; i++)
            cout << 'a';
        return;
    }

    // int useA = dp[aLeft - 1][zLeft];
    int useA = f(aLeft - 1, zLeft);
    // ret = a 사용 후 남은 부분으로 만들 수 있는 갯수
    // kLeft = 사전에서 k번 더 경우의 수 뛰어 넘어야 함
    if (kLeft > useA)
    {
        cout << 'z';
        d(aLeft, zLeft - 1, kLeft - useA);
    }
    else
    {
        cout << 'a';
        d(aLeft - 1, zLeft, kLeft);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    if (f(n, m) < k)
        cout << -1;
    else
        d(n, m, k);
}