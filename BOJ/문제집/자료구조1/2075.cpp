// 2022.01.19 15:21:33
// 2075 https://boj.kr/2075
#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    const int target = n * n - n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0, j = 0, cnt = 0; i < n; i++)
    {
        for (j = 0; j < n; j++, cnt++)
        {
            int tmp;
            cin >> tmp;
            pq.push(tmp);
        }
        if (n == 1)
        {
            cout << pq.top();
            break;
        }
        if (pq.size() > n)
        {
            if (cnt > target)
            {
                for (int s = 0; s < cnt - target; s++)
                    pq.pop();
                cout << pq.top();
                break;
            }
            else
            {
                for (int s = 0; s < n; s++)
                    pq.pop();
            }
        }
    }
}