// 2021.12.29 22:50:44
// 1707 https://boj.kr/1707
#include <bits/stdc++.h>
using namespace std;
#define RED 1
#define GREEN 2
#define VERTEX_MAX 20'001
#define EDGE_MAX 200'001

vector<vector<int>> edges(EDGE_MAX, vector<int>());
int visited[VERTEX_MAX];

int invertColor(int color)
{
    return color == RED ? GREEN : RED;
}

bool dfs(int vertex, int color)
{
    visited[vertex] = color;

    for (int next : edges[vertex])
    {
        if (visited[next] == color)
            return false;
        if (!visited[next] && !dfs(next, invertColor(color)))
            return false;
    }
    return true;
}

void init()
{
    for (int i = 1; i < EDGE_MAX; i++)
        edges[i].clear();
    for (int i = 1; i < VERTEX_MAX; i++)
        visited[i] = 0;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    while (k--)
    {
        int v, e;
        cin >> v >> e;

        init();
        for (int i = 0; i < e; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            edges[v1].push_back(v2);
            edges[v2].push_back(v1);
        }
        bool ret = true;
        for (int i = 1; i <= v; i++)
        {
            if (!visited[i] && !(ret = dfs(i, RED)))
                break;
        }
        cout << (ret ? "YES" : "NO") << '\n';
    }
}