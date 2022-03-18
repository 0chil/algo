// 2022.03.18 17:17:08
// 10815 https://boj.kr/10815
#include <bits/stdc++.h>
using namespace std;
vector<int> card;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        card.push_back(c);
    }
    sort(card.begin(), card.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        auto lo = lower_bound(card.begin(), card.end(), k);
        auto hi = upper_bound(card.begin(), card.end(), k);
        cout << hi - lo << ' ';
    }
}