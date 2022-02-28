// 2022.02.27 14:45:10
// 11401 https://boj.kr/11401
#include <bits/stdc++.h>
#define M 1'000'000'007
using namespace std;

long long f(long long num, long long pow)
{
    if (pow == 1)
        return num % M;

    long long x = f(num, pow / 2);
    x = (x * x) % M;
    if (pow % 2 == 0)
        return x;
    return x * num % M;
}

// nCk =       n!  ( = A )
//       ---------------
//        k! * (n-k)! ( = B )
// = A/B mod M
// = A*B^(-1) mod M
// = A*B^(M-2) mod M
long long bi(long long n, long long k)
{
    long long A = 1, B = 1;
    for (long long i = 1; i <= n; i++)
    {
        A *= i;
        A %= M;
    }
    for (long long i = 1; i <= k; i++)
    {
        B *= i;
        B %= M;
    }
    for (long long i = 1; i <= n - k; i++)
    {
        B *= i;
        B %= M;
    }

    return (A * f(B, M - 2)) % M;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    long long n, k;
    cin >> n >> k;

    cout << bi(n, k);
}