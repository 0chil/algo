#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = -1;

    stack<char> sc;

    for (int i = 0; i < s.length(); i++)
    {
        if (!sc.empty())
        {
            if (sc.top() == s[i])
            {
                // 짝이 지어지는 경우
                sc.pop();
            }
            else
            {
                // 짝이 안지어지는 경우
                sc.push(s[i]);
            }
        }
        else
        {
            // 스택이 빈 경우
            sc.push(s[i]);
        }
    }

    answer = (sc.empty());

    return answer;
}