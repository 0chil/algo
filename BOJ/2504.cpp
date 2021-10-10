// 2021.10.10 19:21:21
// 2504 https://boj.kr/2504
#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool valid = true;
    cin.tie(0);
    ios::sync_with_stdio(false);
    char c;
    stack<char> s;
    stack<int> num;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (c == ')')
        {
            if (s.size() && s.top() == '(')
            {
                int number = 2;
                s.pop();
                if (s.size() && s.top() == '_')
                {
                    number += num.top();
                    num.pop();
                    s.pop();
                }
                s.push('_');
                num.push(number);
            }
            else if (s.size() && s.top() == '_')
            {
                int number = num.top();
                num.pop();
                s.pop(); //pop '_'
                if (s.size() && s.top() == '(')
                {
                    s.pop(); // pop '('

                    number *= 2;
                    if (s.size() && s.top() == '_')
                    {
                        number += num.top();
                        num.pop();
                        s.pop();
                    }
                    s.push('_');
                    num.push(number);
                }
                else
                {
                    valid = false;
                    break;
                }
            }
            else
            {
                valid = false;
                break;
            }
        }
        else if (c == ']')
        {
            if (s.size() && s.top() == '[')
            {
                int number = 3;
                s.pop();
                if (s.size() && s.top() == '_')
                {
                    number += num.top();
                    num.pop();
                    s.pop();
                }
                s.push('_');
                num.push(number);
            }
            else if (s.size() && s.top() == '_')
            {
                int number = num.top();
                num.pop();
                s.pop(); //pop '_'
                if (s.size() &&s.top() == '[')
                {
                    s.pop(); // pop '['

                    number *= 3;
                    if (s.size() && s.top() == '_')
                    {
                        number += num.top();
                        num.pop();
                        s.pop();
                    }
                    s.push('_');
                    num.push(number);
                }
                else
                {
                    valid = false;
                    break;
                }
            }
            else
            {
                valid = false;
                break;
            }
        }
        else
        {
            s.push(c);
        }
    }

    if (num.size() != 1 || !valid)
    {
        cout << 0;
    }
    else
    {
        cout << num.top();
    }
}