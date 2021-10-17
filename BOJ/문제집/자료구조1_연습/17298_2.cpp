// 2021.10.01 16:19:34
// 17298 https://boj.kr/17298
#include <bits/stdc++.h>
using namespace std;

class Num
{
public:
    int number, idx;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, input;
    cin >> n;
    stack<Num> s;
    vector<int> answer(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        while (s.size() && s.top().number < input)
        {
            answer[s.top().idx] = input;
            s.pop();
        }

        s.push(Num{input, i});
    }

    for(auto& ans : answer)
        cout << ans << ' ';
}