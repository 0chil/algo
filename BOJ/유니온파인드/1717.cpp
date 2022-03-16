// 2022.03.16 09:59:33
// 1717 https://boj.kr/1717
#include <bits/stdc++.h>
using namespace std;

int parent[1'000'001];

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
    parent[b] = a;
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
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1)
        {
            cout << (isUnion(a, b) ? "YES\n" : "NO\n");
        }
        else
        {
            join(a, b);
        }
    }
}