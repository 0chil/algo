// 2021.11.04 11:46:00
// 2696 https://boj.kr/2696
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        priority_queue<int, vector<int>, less<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;
        int n, input;
        cin >> n;

        cout << (n+1) /2 << '\n';

        for (int i = 1; i <= n; i++)
        {
            cin >> input;

            // 정렬되도록 삽입
            if (left.empty() && right.empty())
            {
                left.push(input);
            }
            else if (left.empty())
            {
                if (right.top() > input)
                {
                    left.push(input);
                }
                else
                {
                    right.push(input);
                }
            }
            else if (right.empty())
            {
                if (left.top() > input)
                {
                    left.push(input);
                }
                else
                {
                    right.push(input);
                }
            }else{
                if (left.top() > input)
                {
                    left.push(input);
                }
                else
                {
                    right.push(input);
                }
            }

            if (i % 2 == 1)
            {
                // 정렬되면 왼쪽 -1 == 오른쪽으로 만듬.
                while (right.size() && left.size() - 1 < right.size())
                {
                    left.push(right.top());
                    right.pop();
                }
                while (left.size() && left.size() - 1 > right.size())
                {
                    right.push(left.top());
                    left.pop();
                }
                // 그럼 왼쪽의 top이 중앙값
                cout << left.top();
            }

            // 끝 처리
            if (i % 20 == 0)
            {
                cout << '\n';
            }
            else if (i == n)
            {
                if (t != 0)
                {
                    cout << '\n';
                }
            }
            else if(i%2 ==0){

            }
            else
            {
                cout << ' ';
            }
        }
    }
}