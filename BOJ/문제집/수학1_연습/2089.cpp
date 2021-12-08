// 2021.12.08 13:36:41
// 1212 https://boj.kr/1212
#include <bits/stdc++.h>
using namespace std;

stack<char> nDecToBinary(int num)
{
    stack<char> ret;
    if(num == 0){
        ret.push('0');
    }
    while (num)
    {
        int leftover = num % (-2);
        num = num / (-2);
        if (leftover < 0)
        {
            leftover = 1;
            num += 1;
        }
        ret.push(leftover + '0');
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int num;
    cin >> num;

    stack<char> s = nDecToBinary(num);
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
}