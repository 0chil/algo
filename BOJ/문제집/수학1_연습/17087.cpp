// 2021.09.17 22:43:14
// 17087 https://boj.kr/17087
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    vector<int> spaces;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        spaces.push_back(abs(a - x));
    }

    int answer = spaces[0];
    for (int i = 1; i < spaces.size(); i++)
    {
        answer = gcd(answer, spaces[i]);
    }

    cout << answer;
}