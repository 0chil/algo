// 2021.09.11 15:55:03
// 1935 http://boj.kr/1935
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    string postfix;
    cin >> n >> postfix;
    vector<int> numbers;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        numbers.push_back(num);
    }

    stack<double> s;
    int result = 0;
    for (int i = 0; i < postfix.size(); i++)
    {
        if (postfix[i] == '*')
        {
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            s.push(a * b);
        }
        else if (postfix[i] == '/')
        {
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            s.push(a / b);
        }
        else if (postfix[i] == '+')
        {
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            s.push(a + b);
        }
        else if (postfix[i] == '-')
        {
            double b = s.top();
            s.pop();
            double a = s.top();
            s.pop();
            s.push(a - b);
        }
        else
        {
            s.push(numbers[postfix[i] - 'A']);
        }
    }
    cout.precision(2);
    cout << fixed << s.top();
}