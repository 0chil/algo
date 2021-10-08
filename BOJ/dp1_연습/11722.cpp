// 2021.10.08 22:46:10
// 11722 https://boj.kr/11722
#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int dp[1001];
// 가장 긴 감소하는 부분수열 길이
int f(int pos)
{
    if (pos >= a.size())
        return 0;
    int &ret = dp[pos];
    if (ret)
        return ret;
    ret = 1;
    for (int next = pos + 1; next < a.size(); next++)
    {
        if (a[pos] > a[next])
        {
            ret = max(ret, f(next) + 1);
        }
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, input;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        a.push_back(input);
    }

    int greatest = 0;
    for (int i = 0; i < n; i++)
    {
        greatest = max(greatest, f(i));
    }

    cout << greatest;
}