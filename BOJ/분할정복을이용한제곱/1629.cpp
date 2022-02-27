// 2022.02.27 16:40:29
// 1629 https://boj.kr/1629
#include <bits/stdc++.h>
using namespace std;

int a, b, c;

// O(logn), 문제 크기가 매번 절반으로 줄어듦.
int fpow(int n)
{
    if (n == 1)
        return a % c;

    int x = fpow(n / 2) % c;
    x = ((long long)x * x) % c;
    if (n % 2 == 0)
    {
        return x;
    }
    else
    {
        return ((long long)x * a) % c;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    cout << fpow(b);
}