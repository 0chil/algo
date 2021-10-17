// 2021.09.11 22:04:37
// 1918 https://boj.kr/1918
#include <bits/stdc++.h>
using namespace std;

//어려웠음. 며칠 후 다시 시도

//TC : (A+(B*C))-(D/E)
// A+B*C*((D-E)*G) => ABC*DE-G**+
// A*((B*C)*D)*E -> ABC*D**E*

bool is_primary(char &c)
{
    return (c == '*' || c == '/');
}

bool is_secondary(char &c)
{
    return (c == '+' || c == '-');
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    char c;
    stack<char> oprt;
    int brk_cnt = 0;
    while ((c = getchar()))
    {
        if (is_primary(c))
        {
            while(!oprt.empty() && is_primary(oprt.top())){
               cout << oprt.top();
               oprt.pop();
            }
            oprt.push(c);
        }
        else if (is_secondary(c))
        { 
            //브라켓 안에있으면 상대적 우선순위. 브라켓 열리는 곳까지 pop
            while(!oprt.empty() && oprt.top() != '('){
               cout << oprt.top();
               oprt.pop();
            }
            oprt.push(c);
        }
        else if (c == '(')
        {
            oprt.push(c);
        }
        else if (c == ')')
        {
           while(!oprt.empty() && oprt.top()!='('){
               cout << oprt.top();
               oprt.pop();
           }
           oprt.pop();
           // ( 부터 ) 까지 처리 및 pop
        }
        else if (c == '\n')
        {
            while (!oprt.empty())
            {
                cout << oprt.top();
                oprt.pop();
            }
            break;
        }
        else
        {
            cout << c;
        }
    }
}