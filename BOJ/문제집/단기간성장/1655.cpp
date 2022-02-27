// 2022.02.26 16:27:26
// 1655 https://boj.kr/1655
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        if (l.size() && r.size())
        {
            if (l.top() <= tmp)
            {
                r.push(tmp);
            }
            else
            {
                l.push(tmp);
            }
            while (l.size() > r.size())
            {
                r.push(l.top());
                l.pop();
            }
            while (l.size() < r.size())
            {
                l.push(r.top());
                r.pop();
            }
        }
        else
        {
            if (l.size())
            {
                if(l.top() > tmp)
                {
                    r.push(l.top());
                    l.pop();
                    l.push(tmp);
                }
                else{
                    r.push(tmp);
                }
            }
            else
            {
                l.push(tmp);
            }
        }
        cout << "l.size() = " << l.size() << ", r.size() = " << r.size() << endl;
        cout << l.top() << "\n";
    }
}