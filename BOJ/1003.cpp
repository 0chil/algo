// 2022.03.02 19:04:52
// 1003 https://boj.kr/1003
#include <bits/stdc++.h>
using namespace std;

int dp0[41];
int dp1[41];
int zero = 0, one = 0;
int f(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if(n == 1)
        return 0;

    int &ret = dp0[n];
    if (ret != -1)
    {
        return ret;
    }

    return ret = f(n - 1) + f(n - 2);
}

int d(int n)
{
    if( n== 0){
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    int &ret = dp1[n];
    if (ret != -1)
    {
        return ret;
    }

    return ret = d(n - 1) + d(n - 2);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int t, n;
    cin >> t;
    memset(dp0, -1, sizeof(dp0));
    memset(dp1, -1, sizeof(dp1));
    while (t--)
    {
        cin >> n;
        cout << f(n) << ' ' << d(n) << '\n';
    }
}