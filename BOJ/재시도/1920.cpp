// 2022.03.18 10:55:21
// 1920 https://boj.kr/1920
#include <bits/stdc++.h>
using namespace std;

int numbers[100001];
int n, m;

bool find(int x)
{
    int lo = 0, hi = n - 1;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        if (numbers[mid] < x)
            lo = mid + 1;
        else if (numbers[mid] > x)
            hi = mid - 1;
        else
            break;
    }
    return numbers[(lo + hi) / 2] == x;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    sort(numbers, numbers + n);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        cout << find(x) << '\n';
    }
}