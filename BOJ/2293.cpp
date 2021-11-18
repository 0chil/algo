// 2021.11.18 13:00:09
// 2293 https://boj.kr/2293
#include <bits/stdc++.h>
using namespace std;

int coins[101];
int n, k;

int dp[10001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;

    int coin;
    for (int i = 0; i < n; i++)
    {
        cin >> coin;
        coins[i] = coin;
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        // cout << "i :" << i << "번째 동전을 쓰는 경우, "<< coins[i] << "원\n";
        for (int j = coins[i]; j <= k; j++)
        {
            dp[j] = dp[j] + dp[j - coins[i]];
            // cout << "\tj :" << j << ", dp["<< j << "]: "  << dp[j] << '\n';
        }
    }

    // for(int i=0;i<n;i++){
    //     cout <<"dp["<< i << "]: " << dp[i] << endl;
    // }
    cout << dp[k];
}