// 2022.03.18 17:17:08
// 10815 https://boj.kr/10815
#include <bits/stdc++.h>
using namespace std;
int card[500001];
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> card[i];
    sort(card, card + n);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        int lo = 0, hi = n-1;
        int mid = 0;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (card[mid] < k)
                lo = mid + 1;
            else if (card[mid] > k)
                hi = mid - 1;
            else
                break;
        }
        cout << (card[mid] == k) << ' ';
    }
}