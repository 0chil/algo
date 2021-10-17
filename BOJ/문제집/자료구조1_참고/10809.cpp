// 2021.09.12 16:29:59
// 10809 https://boj.kr/10809
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int o[26];
    for (auto &num : o)
    {
        num = -1;
    }

    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (o[s[i] - 'a'] == -1)
            o[s[i] - 'a'] = i;
    }

    for(int i=0;i<26;i++){
        cout << o[i];
        if(i!=25) cout <<" ";
    }
}