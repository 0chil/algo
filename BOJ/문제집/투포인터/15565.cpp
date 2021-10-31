// 2021.10.31 11:07:55
// 15565 https://boj.kr/15565
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k, input;
    vector<int> doll;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        doll.push_back(input);
    }
    int length = 1000001;
    int i = 0, j = i;
    int cnt = (doll[i] == 1);
    while (j < n)
    {
        if (cnt < k)
        {
            j++;
            cnt += doll[j] == 1;
        }
        else if (cnt >= k)
        {
            length = min(length, j - i + 1);
            cnt -= doll[i] == 1;
            i++;
        }
    }

    if (length == 1000001)
        cout << -1;
    else
        cout << length;
}