// 2021.11.19 23:33:29
// 11724 https://boj.kr/11724
#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > v(1001, vector<int>());
bool visited[1001];

void dfs(int currentNode)
{
    visited[currentNode] = true;

    for (auto &vertex : v[currentNode])
    {
        if (visited[vertex])
            continue;
        dfs(vertex);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int e1, e2;
        cin >> e1 >> e2;

        v[e1].push_back(e2);
        v[e2].push_back(e1);
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i])
            continue;
        dfs(i);
        answer++;
    }

    cout << answer;
}