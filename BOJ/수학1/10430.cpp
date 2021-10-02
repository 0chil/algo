// 2021.09.13 19:15:45
// 10430 https://boj.kr/10430
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;
    cout << (A + B) % C << '\n'
         << ((A % C) + (B % C)) % C << '\n'
         << (A * B) % C << '\n'
         << ((A % C) * (B % C)) % C;
}