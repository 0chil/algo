// 2021.10.09 23:20:20
// 5397 https://boj.kr/5397
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

        string input, answer;
        stack<char> ansl;
        stack<char> ansr;
        cin >> input;
        for (int i = 0; i < input.size(); i++)
        {
            switch (input[i])
            {
            case '<':
                if (ansl.size())
                {
                    ansr.push(ansl.top());
                    ansl.pop();
                }
                break;
            case '>':
                if (ansr.size())
                {
                    ansl.push(ansr.top());
                    ansr.pop();
                }
                break;
            case '-':
                if (ansl.size())
                {
                    ansl.pop();
                }
                break;
            default:
                ansl.push(input[i]);
                break;
            }
        }

        while (ansl.size())
        {
            ansr.push(ansl.top());
            ansl.pop();
        }

        while (ansr.size())
        {
            answer.push_back(ansr.top());
            ansr.pop();
        }
        cout << answer << '\n';
    }
}