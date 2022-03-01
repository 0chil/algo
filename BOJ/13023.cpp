// 2022.03.01 23:15:15
// 13023 https://boj.kr/13023
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> rel = vector<vector<int>>(2001, vector<int>());
int visited[2001];
bool dfs(int cur, int depth)
{
    visited[cur] = true;
    if (depth == 4)
        return true;

    for (int next : rel[cur])
    {
        if (!visited[next] && dfs(next, depth + 1))
        {
            return true;
        }
    }
    visited[cur] = false;
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        rel[a].push_back(b);
        rel[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dfs(i, 0))
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}