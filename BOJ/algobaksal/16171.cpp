// 2023.09.27 11:15:03
// 16171 https://boj.kr/16171
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    string input;
    cin >> input;
    string s;
    for (int i = 0; i < input.size(); i++)
    {
        char &x = input.at(i);
        if (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))
        {
            s += x;
        }
    }

    string keyword;
    cin >> keyword;
    if (s.find(keyword) == string::npos)
    {
        cout << 0 << '\n';
        return 0;
    }
    cout << 1 << '\n';
}