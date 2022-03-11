#include <bits/stdc++.h>
#define BOUND 1'000'000'000
using namespace std;

int n, m, k;
int dp[101][101];
int f(int a, int z)
{
    if (a == 0 || z == 0)
        return 1;

    int &ret = dp[a][z];
    if (ret != -1)
        return ret;
    int usea = f(a - 1, z);
    int useb = f(a, z - 1);
    return ret = min(BOUND + 1, usea + useb);
}

void d(int a, int z, int kLeft)
{
    if (a == 0)
    {
        for (int i = 0; i < z; i++)
            cout << 'z';
        return;
    }
    if (z == 0)
    {
        for (int i = 0; i < a; i++)
            cout << 'a';
        return;
    }

    int leftAfterUseA = f(a - 1, z);
    if (kLeft - leftAfterUseA <= 0)
    {
        cout << 'a';
        d(a - 1, z, kLeft);
    }
    else
    {
        cout << 'z';
        d(a, z - 1, kLeft - leftAfterUseA);
    }
}

int main()
{
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));

    if (f(n, m) < k)
    {
        cout << -1;
    }
    else
    {
        d(n, m, k);
    }
}