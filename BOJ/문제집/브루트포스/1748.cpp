// 2021.10.24 14:37:43
// 1748 https://boj.kr/1748
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    long long sum = 0;

    int counted = 0;
    int l = 1;
    int count = 9;
    while (true)
    {
        if (counted + count > n)
        {
            sum += l * (n - counted);
            break;
        }
        else
        {
            sum += l * count;
            counted += count;

            count *= 10;
            l++;
        }
    }
    //123456789 1*9
    //10111213141516171819...99 2*90
    // 100101... 999 3*900
    cout << sum;
}