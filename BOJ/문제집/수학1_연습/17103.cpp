// 2021.12.28 14:58:24
// 17103 https://boj.kr/17103
#include <bits/stdc++.h>
using namespace std;
#define MAX 1'000'001

bool notPrimeCheck[MAX];
vector<int> primes;
void era()
{
    notPrimeCheck[0] = notPrimeCheck[1] = true;
    for (int i = 2; i < MAX; i++)
    {
        for (int j = i * 2; j < MAX; j += i)
        {
            if (!notPrimeCheck[j])
                notPrimeCheck[j] = true;
        }
    }
    for (int i = 2; i < MAX; i++)
        if (!notPrimeCheck[i])
            primes.push_back(i);
}

int goldThing(int n)
{
    int ret = 0;
    for (int i = 0; primes[i] <= n; i++)
        if (!notPrimeCheck[n - primes[i]])
            ++ret;
    ret /= 2;
    if (!notPrimeCheck[n / 2]) // 3+3 exists
        ++ret;
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    era();
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cout << goldThing(n) << '\n';
    }
}