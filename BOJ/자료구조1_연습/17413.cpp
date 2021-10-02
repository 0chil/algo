// 2021.09.10 20:31:56
// 17413 http://boj.kr/17413
#include <bits/stdc++.h>
using namespace std;

void print_reverse(string &str)
{
    for (int i = str.size() - 1; i >= 0; i--)
    {
        cout << str[i];
    }
}

int main()
{
    string s;
    char c;
    bool print_as_input = false;
    while (c = getchar())
    {
        if (print_as_input)
        {
            cout << c;
        }
        else if (c == ' ')
        {
            print_reverse(s);
            s.clear();
            cout << ' ';
        }
        else if (c == '<')
        {
            print_reverse(s);
            s.clear();
            cout << '<';
            print_as_input = true;
        }
        else if (c == '\n')
        {
            print_reverse(s);
            break;
        }
        else
        {
            s.push_back(c);
        }

        if (c == '>')
        {
            print_as_input = false;
        }
    }
    return 0;
}