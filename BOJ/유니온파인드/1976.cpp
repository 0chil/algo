// 2022.03.16 22:16:19
// 1976 https://boj.kr/1976
#include <bits/stdc++.h>
using namespace std;
int parent[201];

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

    for (int i = 0; i < 201; i++)
    {
        parent[i] = i;
    }

    for (int from = 1; from <= n; from++)
    {
        for (int to = 1; to <= n; to++)
        {
            int connected;
            cin >> connected;
            if (connected)
                join(from, to);
        }
    }

    int start;
    cin >> start;
    start = find(start);
    bool able = true;
    for (int i = 2; i <= m; i++)
    {
        int next;
        cin >> next;
        if(!isUnion(start, next)){
            able = false;
            break;
        }
    }

    if(able)
        cout << "YES";
    else
        cout << "NO";
}