// 2021.10.11 18:25:41
// 10422 https://boj.kr/10422
#include <bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007
int dp[5001][5001];

// 길이가 l 인 괄호열 개수
int f(int length, int depth)
{
    if (depth < 0)
        return 0;
    if (length < 0)
        return 0;
    if (length == 0 && depth == 0)
        return 1;

    int &ret = dp[length][depth];
    if (ret != -1)
        return ret;

    //새로 괄호를 여는 경우
    int openNew = f(length - 1, depth + 1) % MOD;
    //열렸던 괄호를 닫는 경우
    int close = f(length - 1, depth - 1) % MOD;

    return ret = (openNew + close ) % MOD;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < 5001; i++)
    {
        for (int j = 0; j < 5001; j++)
        {
            dp[i][j] = -1;
        }
    }
    while (t--)
    {
        int l;
        cin >> l;
        cout << f(l, 0) << '\n';
    }
}