// 2021.09.18 22:23:13
// 1149 https://boj.kr/1149
#include <bits/stdc++.h>
using namespace std;
#define R 0
#define G 1
#define B 2

int dp[1001][3];
vector<vector<int>> cost;
int f(int n, int color)
{
    if (n == 0)
        return 0;
    int &ret = dp[n][color];
    if (ret)
        return ret;
    ret = 987654321;
    for (int nextcolor = R; nextcolor <= B; nextcolor++)
    {
        if (nextcolor == color)
            continue;
        ret = min(ret, f(n - 1, nextcolor)+cost[n-1][color]);
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> costi;
        for (int j = 0; j < 3; j++)
        {
            int temp_cost;
            cin >> temp_cost;
            costi.push_back(temp_cost);
        }
        cost.push_back(costi);
    }
    cout << min(min(f(n,R),f(n,G)),f(n,B));
}