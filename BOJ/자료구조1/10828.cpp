// 2021.09.08 17:41:22
// 10828 http://boj.kr/10828
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    int n;
    cin >> n;
    while (n--)
    {
        string command;
        int x;
        cin >> command;
        if (command[0] == 'p')
        {
            if (command[1] == 'u')
            {
                cin >> x;
                s.push(x);
            }
            else
            {
                if (s.empty())
                {
                    x = -1;
                }
                else
                {
                    x = s.top();
                    s.pop();
                }
                cout << x << '\n';
            }
        }
        else if (command[0] == 's')
        {
            cout << s.size() << '\n';
        }
        else if (command[0] == 'e')
        {
            cout << s.empty() << '\n';
        }
        else if (command[0] == 't')
        {
            if (s.empty())
            {
                x = -1;
            }
            else
            {
                x = s.top();
            }
            cout << x << '\n';
        }
    }
}