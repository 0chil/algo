// 2022.05.02 15:05:01
// 9020 https://boj.kr/9020
#include <bits/stdc++.h>
using namespace std;
int n;
int prime[10001];

void era()
{
    for (int i = 2; i < 10001; i++)
        prime[i] = i;
    for (int i = 2; i < 10001; i++)
    {
        if (prime[i] == 0)
            continue;
        for (int j = 2 * i; j < 10001; j += i)
        {
            prime[j] = 0;
        }
    }
}

void gp(int number)
{
    int l, r = l = number / 2;
    for (; 2 <= l && r <= number - 2; l--, r++)
    {
        if (prime[l] != 0 && prime[r] != 0)
        {
            cout << l << " " << r << "\n";
            break;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    era();
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        gp(tmp);
    }
}