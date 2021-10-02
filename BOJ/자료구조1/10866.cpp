// 2021.09.11 15:35:15
// 10866 http://boj.kr/10866
#include <bits/stdc++.h>
using namespace std;

class DQ
{
public:
    deque<int> dq;

    void pushf(int x)
    {
        dq.push_front(x);
    }

    void pushb(int x)
    {
        dq.push_back(x);
    }

    void popf()
    {
        dq.pop_front();
    }

    void popb()
    {
        dq.pop_back();
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    DQ dq;
    int n;
    cin >> n;

    string command;
    int x;

    while (n--)
    {
        cin >> command;
        if (command[0] == 'p')
        {
            if (command[5] == 'f')
            {
                cin >> x;
                dq.pushf(x);
            }
            else if (command[5] == 'b')
            {
                cin >> x;
                dq.pushb(x);
            }
            else if (command[4] == 'f')
            {
                if (dq.dq.size())
                {
                    cout << dq.dq.front() << '\n';
                    dq.popf();
                }
                else
                    cout << "-1\n";
            }
            else if (command[4] == 'b')
            {
                if (dq.dq.size())
                {
                    cout << dq.dq.back() << '\n';
                    dq.popb();
                }
                else
                    cout << "-1\n";
            }
        }
        else if (command[0] == 's')
        {
            cout << dq.dq.size() << '\n';
        }
        else if (command[0] == 'e')
        {
            cout << dq.dq.empty() << '\n';
        }
        else if (command[0] == 'f')
        {
            if (dq.dq.size())
            {
                cout << dq.dq.front() << '\n';
            }
            else
                cout << "-1\n";
        }
        else if (command[0] == 'b')
        {
            if (dq.dq.size())
            {
                cout << dq.dq.back() << '\n';
            }
            else
                cout << "-1\n";
        }
    }
}