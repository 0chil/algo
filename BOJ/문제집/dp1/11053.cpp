// 2021.09.23 22:08:47
// 11053 https://boj.kr/11053
#include <bits/stdc++.h>
using namespace std;

int dp[1001];
vector<int> a;
int f(int pos)
{

    int &ret = dp[pos];
    if (ret)
        return ret;
    ret = 1;
    for (int next = pos+1; next < a.size(); next++)
    {
        if (a[pos] < a[next])
            ret = max(ret, f(next) + 1);
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
        int a_i;
        cin >> a_i;
        a.push_back(a_i);
    }

    int ret = 1;
    for (int i = 0; i < n; i++)
    {
        ret = max(ret, f(i));
    }

    cout << ret;
}