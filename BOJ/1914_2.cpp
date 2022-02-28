// 2022.02.28 11:23:38
// 1914_2 https://boj.kr/1914_2
#include <bits/stdc++.h>
using namespace std;

void hanoi(int left, int from, int via, int to)
{
    // 한 문제는 3과정으로 쪼개진다.
    // 1. 제일 큰 판을 제외한 나머지를 via로 이동
    // 2. 제일 큰 판을 to로 이동
    // 3. 나머지를 to로 이동

    if (left == 1)
    {
        cout << from << ' ' << to << '\n';
        return;
    }

    hanoi(left - 1, from, to, via);
    cout << from << ' ' << to << '\n';
    hanoi(left - 1, via, from, to);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string ans = to_string(pow(2, n));
    ans = ans.substr(0, ans.find('.'));
    --ans[ans.length() - 1];
    cout << ans << '\n';
    if (n <= 20)
        hanoi(n, 1, 2, 3);
}