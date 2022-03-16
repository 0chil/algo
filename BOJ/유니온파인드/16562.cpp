// 2022.03.15 21:32:02
// 16562 https://boj.kr/16562
#include <bits/stdc++.h>
using namespace std;
int parent[10001];
int cost[10001];

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
    cost[a] = min(cost[a], cost[b]);
    parent[b] = a;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        join(a, b);
    }

    int costTotal = 0;
    for (int i = 1; i <= n; i++)
    {
        if (parent[i] == i)
            costTotal += cost[i];
    }

    if (costTotal <= k)
        cout << costTotal;
    else
        cout << "Oh no" << '\n';
}