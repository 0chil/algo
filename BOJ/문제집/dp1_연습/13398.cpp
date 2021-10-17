// 2021.10.10 12:45:27
// 13398 https://boj.kr/13398
#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int dp[100001][2];

int f(int pos, int excepted)
{
    if (pos >= a.size())
        return INT_MIN+1001;
    int &ret = dp[pos][excepted];
    if (ret != INT_MIN+1001)
        return ret;

    int include = f(pos + 1, excepted) + a[pos];
    int stop = a[pos];
    int except = INT_MIN+1001;
    if (!excepted)
        except = f(pos + 1, 1);

    return ret = max(max(stop, include), except);
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
        dp[i][0] = dp[i][1] = INT_MIN+1001;
    }

    int biggest = INT_MIN+1001;
    for (int i = 0; i < n; i++)
    {
        biggest = max(f(i, 0), biggest);
    }
    cout << biggest;
}