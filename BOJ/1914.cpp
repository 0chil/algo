// 2021.09.12 22:00:12
// 1914 https://boj.kr/1914
#include <bits/stdc++.h>
using namespace std;

int N;
void hanoi(int n, int from, int via, int to)
{
    if (n == 1)
    {
        cout << from << ' ' << to << '\n';
        return;
    }
    else
    {
        //가장 빠른 규칙으로 하면됨.
        // n-1개 1->2로 이동 하는 문제로 분할
        hanoi(n - 1, from, to, via);
        // 제일 큰 판 1->3, 따로 처리 필요없음.
        cout << from << ' ' << to << '\n';
        // n-1개 2->3으로 이동하는 문제로 분할
        hanoi(n - 1, via, from, to);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    string answer = to_string(pow(2, N));
    answer = answer.substr(0, answer.find('.'));
    answer[answer.length() - 1] -=1;
    cout << answer << '\n';
    if (N <= 20)
        hanoi(N, 1, 2, 3);
}