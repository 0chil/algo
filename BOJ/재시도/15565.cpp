#include <bits/stdc++.h>
using namespace std;

int doll[1000001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> doll[i];
    }

    int i = 0, j = 0;
    int cnt = doll[i] == 1;
    int size = 1000001;
    while (j < n)
    {
        if (cnt < k)
        {
            j++;
            cnt += doll[j] == 1;
        }
        else
        {
            size = min(size, j - i + 1);
            cnt -= doll[i] == 1;
            i++;
        }
    }

    if(size >= 1000001)
        cout << -1;
    else
        cout << size;
}