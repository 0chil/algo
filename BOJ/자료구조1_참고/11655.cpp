// 2021.09.12 17:23:09
// 11655 https://boj.kr/11655
#include <bits/stdc++.h>
using namespace std;

bool is_uppercase(const char &c)
{
    return 'A' <= c && c <= 'Z';
}

bool is_lowercase(const char &c)
{
    return 'a' <= c && c <= 'z';
}

void rot13(char &c)
{
    if (is_uppercase(c))
    {

        c = (c - 'A' + 13) % 26 + 'A';
    }
    else if(is_lowercase(c))
    {
        c = (c - 'a' + 13) % 26 + 'a';
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    getline(cin, s);

    for (int i = 0; i < s.length(); i++)
    {
        rot13(s[i]);
    }

    cout << s;
}