// 2021.09.08 19:49:34
// 1874 http://boj.kr/1874
#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    int n;
    cin >> n;
    int it = 1;
    string res;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;

        // push for later use
        while (it <= input)
        {
            s.push(it++);
            res.push_back('+');
        }

        // pop one that is same as input
        if (s.top() != input)
        {
            // impossible case
            cout <<"NO\n";
            return 0;
        }
        s.pop();
        res.push_back('-');
    }
    for(int i=0;i<res.size();i++){
        cout << res[i] << '\n';
    }
}