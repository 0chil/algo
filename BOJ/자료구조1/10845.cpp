// 2021.09.08 23:21:06
// 10845 http://boj.kr/10845
#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    queue<int> q;

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        if (q.empty())
            return -1;
        int front = q.front();
        q.pop();
        return front;
    }

    int size()
    {
        return q.size();
    }

    bool empty()
    {
        return q.empty();
    }

    int front()
    {
        if (q.empty())
            return -1;
        return q.front();
    }

    int back()
    {
        if (q.empty())
            return -1;
        return q.back();
    }
};

int main()
{
    int n, x;
    cin >> n;
    Queue q;
    while (n--)
    {
        string command;
        cin >> command;
        if (command[0] == 'p')
        {
            if (command[1] == 'u')
            {
                cin >> x;
                q.push(x);
            }
            else
            {
                cout << q.pop() << '\n';
            }
        }
        else if (command[0] == 's')
        {
            cout << q.size() << '\n';
        }
        else if (command[0] == 'e')
        {
            cout << q.empty() << '\n';
        }
        else if (command[0] == 'f')
        {
            cout << q.front() << '\n';
        }
        else if (command[0] == 'b')
        {
            cout << q.back() << '\n';
        }
    }
}