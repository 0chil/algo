// 2021.09.09 23:24:40
// 1158 http://boj.kr/1158
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        v.push_back(i);

    cout << "<";
    int cnt = 0;
    int it = 0;
    int itcnt = 0;
    while (cnt < n)
    {
        if (v[it] != -1)
        {
            itcnt++;
            if (itcnt % k == 0)
            {
                cnt++;
                if(cnt < n)
                    cout << v[it] << ", ";
                else
                    cout << v[it];
                v[it] = -1;
            }
        }

        it++;
        if (it >= n)
            it = 0;
    }
    cout << ">\n";
}