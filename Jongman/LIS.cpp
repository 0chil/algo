#include <bits/stdc++.h>
using namespace std;
int n, s[500], cache[501];
int f(int pos)
{
    int &ret = cache[pos + 1];
    if (ret != -1)
        return ret;
    if (pos >= n)
        return 0;
    ret = 1;
    for (int i = pos + 1; i < n; i++)
    {
        if (pos == -1 || s[pos] < s[i])
        {
            ret = max(ret, f(i) + 1);
        }
    }
    return ret;
}

int main()
{
    int c;
    cin >> c;
    while (c--)
    {
        cin >> n;
        for (int i = 0; i < 501; i++)
            cache[i] = -1;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        cout << f(-1) - 1 << '\n';
    }
}