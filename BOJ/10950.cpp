// 2021.09.22 22:52:00
// 10950 https://boj.kr/10950
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a = -1, b = -1;
    char c;
    while ((c = getchar()))
    {
        if(c == ' ') continue;
        if (a == -1)
        {
            a = c - '0';
        }
        else if (b == -1)
        {
            b = c - '0';
        }
        else
        {
            cout << a + b << '\n';
            a=b=-1;
        }
        if(c==EOF) break;
    }
}