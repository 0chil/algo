// 2022.03.17 23:49:55
// 2805 https://boj.kr/2805
#include <bits/stdc++.h>
using namespace std;

int tree[1'000'001];
int n, m;
bool check(int h)
{
    long long remain = 0;
    for (int i = 0; i < n; i++)
    {
        remain += (tree[i] > h) ? tree[i] - h : 0;
    }
    return remain >= m;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> tree[i];

    // (남은길이를 m 보다 크게하는) 가장 긴 높이

    int lo = 0;
    int hi = 1e9;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        if (true == check(mid)) // check(lo) should be true, then check(mid) could be true
            lo = mid;
        else
            hi = mid;
    }
    // biggest true
    cout << lo;
}