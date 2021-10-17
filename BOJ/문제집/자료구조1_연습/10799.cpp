// 2021.09.10 23:25:49
// 10799 http://boj.kr/10799
#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    char old_c = 0;
    int cnt = 0;
    stack<char> s;
    while ((c = getchar()) != '\n')
    {
        if (c == '(')
        {
            s.push(c);
        }
        else if (old_c =='(' && c == ')')
        {
            s.pop();
            cnt += s.size();
        }
        else if (old_c ==')' && c == ')')
        {
            s.pop();
            cnt+=1;
        }
        old_c = c;
    }
    cout << cnt;
}