// 2021.10.23 17:19:50
// 1920 https://boj.kr/1920
#include <bits/stdc++.h>
using namespace std;

vector<int> a;

bool bs(int left, int right, int target)
{
    if (left > right)
    {
        return false;
    }
    int mid = (left + right) / 2;
    if (a[mid] == target)
    {
        return true;
    }

    if (a[mid] < target)
    {
        return bs(mid + 1, right, target);
    }

    if (a[mid] > target)
    {
        return bs(left, mid - 1, target);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, input;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        a.push_back(input);
    }

    sort(a.begin(), a.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> input;
        cout << bs(0, n - 1, input) << '\n';
    }
}