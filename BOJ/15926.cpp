// 2022.01.04 16:51:36
// 15926 https://boj.kr/15926
#include <bits/stdc++.h>
using namespace std;
bool valid[200001];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    stack<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (c == '(')
        {
            s.push(i);
        }
        if (c == ')' && !s.empty())
        {
            valid[i] = valid[s.top()] = true;
            s.pop();
        }
    }

    int ans = 0;
    int ansMax = 0;
    for (int i = 0; i < n; i++)
        if (valid[i])
        {
            ++ans;
            ansMax = max(ansMax, ans);
        }
        else
        {
            ans = 0;
        }
    cout << ansMax;
}