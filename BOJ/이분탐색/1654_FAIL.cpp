// 2022.03.18 13:49:29
// 1654 https://boj.kr/1654
#include <bits/stdc++.h>
using namespace std;
long long k, n;
long long len[10001];

bool with(long long length)
{
    long long ret = 0;
    for (int i = 0; i < k; i++)
        ret += len[i] / length;
    return ret >= n;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        cin >> len[i];
    }

    long long lo = 1LL, hi = 2147483647LL;
    while (lo + 1 < hi)
    {
        long long mid = (lo + (long long)hi) / 2;
        if (true == with(mid))
            lo = mid;
        else
            hi = mid;
    }
    cout << lo;
}