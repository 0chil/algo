// 2022.03.05 13:06:24
// 15565 https://boj.kr/15565
#include <bits/stdc++.h>
using namespace std;

int dolls[1000001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> dolls[i];
    }

    int mini = 1000001;
    int i = 0, j = i;
    int cnt = dolls[i] == 1;
    while (j < n)
    {
        if (cnt < k)
        {
            j++;
            cnt += dolls[j] == 1;
        }
        else
        {
            mini = min(mini, j - i + 1);
            cnt -= dolls[i] == 1;
            i++;
        }
    }

    if (mini == 1000001)
        cout << "-1";
    else
        cout << mini;
}