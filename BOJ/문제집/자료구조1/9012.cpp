// 2021.09.08 19:37:37
// 9012 http://boj.kr/9012
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        stack<int> s;
        string input;
        cin >> input;
        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] == '(')
                s.push(0);
            else
            {
                if (s.empty())
                {
                    s.push(-1);
                    break;
                }
                s.pop();
            }
        }
        if (s.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}