// 2021.09.14 22:58:18
// 6588 https://boj.kr/6588
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<bool> prime(1000001, true);
    vector<int> odd_prime_numbers;

    for (int i = 2; i * i <= 1000000; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = 3; i <= 1000000; i += 2)
    {
        if (prime[i])
            odd_prime_numbers.push_back(i);
    }

    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        bool found = false;
        for (int a = 0; ( a < odd_prime_numbers.size() && odd_prime_numbers[a] <= n - 3); a++)
        {
            int b = n-odd_prime_numbers[a];
            if(prime[b]){
                cout << n << " = " << odd_prime_numbers[a] << " + " << b << '\n';
                found = true;
                break;
            }
        }
        if(!found) cout << "Goldbach's conjecture is wrong.";
    }
}