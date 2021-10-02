// 2021.09.09 19:02:12
// 1463 http://boj.kr/1463
#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int f(int x)
{
    if (x == 1)
        return 0;
    if (dp[x] != -1)
        return dp[x];

    int compute = INT_MAX;
    if (x % 3 == 0)
        compute = min(compute, f(x / 3) + 1);
    if (x % 2 == 0)
        compute = min(compute, f(x / 2) + 1);
    return dp[x] = min(compute, f(x - 1) + 1);
}

int main()
{
    for(auto &num : dp)
        num = -1;
    int n;
    cin >> n;
    
    cout << f(n);
}