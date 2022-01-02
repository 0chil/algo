// 2022.01.03 10:26:18
// 13023_2 https://boj.kr/13023_2
#include <bits/stdc++.h>
using namespace std;
int n, m;

vector<vector<int>> rel(2001, vector<int>());
bool visited[2001];
bool dfs(int cur, int depth)
{
    if (depth == 4)
        return true;
    visited[cur] = true;

    for (int &next : rel[cur])
    {
        if (!visited[next] && dfs(next, depth + 1))
            return true;
    }
    visited[cur] = false;
    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        rel[a].push_back(b);
        rel[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && dfs(i, 0)){
            cout << 1;
            return 0;
        }
    }
    cout << 0;
}