// 2021.12.08 13:36:41
// 1212 https://boj.kr/1212
#include <bits/stdc++.h>
using namespace std;

string octalToBinary(char c)
{
    string ret(3, '0');
    int mul[3] = {4, 2, 1};
    int it = 0;
    c -= '0';
    for (int i = 0; i < 3; i++)
    {
        if (c - mul[i] >= 0)
        {
            c -= mul[i];
            ret[i] = '1';
        }
    }
    return ret;
}

string trim(string s)
{
    int from = 0, to = s.size();
    for (from = 0; from < to; from++)
        if (s[from] == '1')
            break;
    return s.substr(from, to - from);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    string ans;
    for (auto& c : s)
    {
        for (auto cc : octalToBinary(c))
            ans += cc;
    }
    if (s.size() == 1 && s[0] == '0')
        cout << '0';
    else
        cout << trim(ans);
}