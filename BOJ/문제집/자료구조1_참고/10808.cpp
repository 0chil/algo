// 2021.09.12 16:15:18
// 10808 https://boj.kr/10808
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int f[26];
    for (auto &num : f)
    {
        num = 0;
    }

    string s;
    cin >> s;
    for (auto &c : s)
    {
        f[c - 'a']++;
    }

    for (int i=0;i<26;i++)
    {
        cout << f[i];
        if(i!=25) cout << " ";
    }
}