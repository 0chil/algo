// 2021.10.12 23:43:00
// 10815 https://boj.kr/10815
#include <bits/stdc++.h>
using namespace std;
#define OFFSET 10'000'000
int arr[20'000'001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m, input;
    cin >> n;
    while (n--)
    {
        cin >> input;
        arr[OFFSET + input]++;
    }

    cin >> m;
    while (m--)
    {
        cin >> input;
        cout << (arr[OFFSET + input] > 0) << " ";
    }
}