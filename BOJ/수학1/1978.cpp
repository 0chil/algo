// 2021.09.14 22:14:09
// 1978 https://boj.kr/1978
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v;
    vector<bool> prime(1024, true);

    for (int i = 2; i * i <= 1000; i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= 1000; j += i)
            {
                //i*i 부터 시작하는 이유: 기존것은 이미 처리 되어있음.
                prime[j] = false;
            }
        }
    }

    int prime_cnt = 0;
    while (n--)
    {
        int given;
        cin >> given;

        if (given != 1 && prime[given])
        {
            prime_cnt++;
        }
    }
    cout << prime_cnt;
}