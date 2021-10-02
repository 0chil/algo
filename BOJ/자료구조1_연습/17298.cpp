// 2021.09.11 11:10:03
// 17298 http://boj.kr/17298
#include <bits/stdc++.h>
using namespace std;

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
    stack<Num> s;
    vector<int> result(n, -1);
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        while(s.size() && input > s.top().num){
            result[s.top().idx]= input;
            s.pop();
        }

        s.push(Num(input,i));
    }

    for (int i = 0; i < n; i++)
    {
        cout << result[i];
        if (i != n - 1)
            cout << " ";
    }
}