// 2022.03.15 20:41:56
// 2606 https://boj.kr/2606
#include <bits/stdc++.h>
using namespace std;

int parent[101];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);
    parent[a] = b;
}

bool isUnion(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return true;
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        join(a, b);
    }

    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        cnt += isUnion(1, i);
    }
    cout << cnt;
}