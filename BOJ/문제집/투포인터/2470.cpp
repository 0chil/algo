// 2022.01.20 12:54:59
// 2470 https://boj.kr/2470
#include <bits/stdc++.h>
using namespace std;

int n;
int number[100001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> number[i];
    sort(number, number + n);

    int left = 0, right = n - 1, mini = 20'0000'0001;
    int sl = 0, sr = 0;
    while (left < right)
    {
        int sum = number[left] + number[right];
        int diff = abs(sum);
        if (diff < mini)
        {
            sl = left;
            sr = right;
            mini = diff;
        }

        if (sum < 0)
            left++;
        else
            right--;
    }
    cout << number[sl] << " " << number[sr];
}
/*
8
-100 -99 99 1 2 3 4 5
*/