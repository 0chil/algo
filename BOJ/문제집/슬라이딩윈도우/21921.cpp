// 2022.01.21 15:38:38
// 21921 https://boj.kr/21921
#include <bits/stdc++.h>
using namespace std;

int n, x;
int num[250001];
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    int start = 0, end = start + x - 1;
    int sum = accumulate(num, num + x, 0);
    int maxi = 0, maxicnt = 0;
    while (true)
    {
        if (sum > maxi)
        {
            maxi = sum;
            maxicnt = 1;
        }
        else if (sum == maxi)
        {
            maxicnt++;
        }

        if (end + 1 == n)
            break;
        sum -= num[start];
        sum += num[end + 1];
        start++;
        end++;
    }

    if (maxi)
        cout << maxi << '\n'
             << maxicnt;
    else
        cout << "SAD\n";
}