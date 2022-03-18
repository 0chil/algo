// 2022.03.18 13:49:29
// 1654 https://boj.kr/1654
#include <bits/stdc++.h>
using namespace std;
int k, n;
int len[10001];

long long with(long long length)
{
    long long ret = 0LL;
    for (int i = 0; i < k; i++)
        ret += len[i] / length;
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    cin >> k >> n;
    for (int i = 0; i < k; i++){
        cin >> len[i];
    }

    long long lo = 1LL, hi = 2147483647LL;
    while (lo <= hi)
    {
        long long mid = (lo + (long long)hi) / 2LL;
        long long cnt = with(mid);
        if (cnt >= n)
            lo = mid+1;
        else if(cnt < n)
            hi = mid-1;
    }
    cout << (lo+hi)/2;
}