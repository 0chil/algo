// 2021.09.11 14:58:08
// 17299 http://boj.kr/17299
#include <bits/stdc++.h>
using namespace std;

int f[1000001];

class Num
{
public:
    Num(int n, int i)
    {
        num = n;
        idx = i;
    }
    int num;
    int idx;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a;
    vector<int> result(n, -1);
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        a.push_back(input);
        f[input]++;
    }

    stack<Num> s;
    for (int i = 0; i < n; i++)
    {
        while (s.size() && f[s.top().num] < f[a[i]])
        {
            result[s.top().idx] = a[i];
            s.pop();
        }
        s.push(Num(a[i], i));
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i];
        if (i != n - 1)
            cout << " ";
    }
}