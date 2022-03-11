// 2022.03.11 15:48:49
// 2629 https://boj.kr/2629
#include <bits/stdc++.h>
using namespace std;
int weight[31];
int dp[31][15001];

int n, tw;
int f(int wi, int sum)
{
    if (sum == tw)
        return 1;
    if (wi >= n)
        return 0;
    int &ret = dp[wi][sum];
    if (ret != -1)
        return ret;

    int onLeft = f(wi + 1, abs(sum - weight[wi]));
    // 뒤집혀도 총량만 같으면 같은문제다.
    int onRight = f(wi + 1, sum + weight[wi]);
    int skip = f(wi + 1, sum);
    return ret = skip || onLeft || onRight;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    int tc;
    cin >> tc;
    while (tc--)
    {
        memset(dp, -1, sizeof(dp));
        cin >> tw;
        cout << (f(0, 0) ? 'Y' : 'N');
        if (tc > 0)
        {
            cout << ' ';
        }
    }
}