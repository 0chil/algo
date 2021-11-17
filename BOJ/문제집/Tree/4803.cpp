// 2021.11.16 17:20:38
// 4803 https://boj.kr/4803
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
int visited[501];

void clearVisited()
{
    for (int i = 0; i < 501; i++)
    {
        visited[i] = 0;
    }
}

bool dfs(int currentNode, int from)
{
    visited[currentNode] += 1;
    if (visited[currentNode] > 1)
        return false;

    bool ret = true;
    for (auto &node : v[currentNode])
    {
        if (node == from)
            continue;
        ret = min(ret, dfs(node, currentNode));
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    int caseNum = 0;
    while (cin >> n >> m)
    {
        ++caseNum;
        if (n == 0 && m == 0)
            return 0;

        int e1, e2;
        v = vector<vector<int>>(n + 1, vector<int>());
        clearVisited();

        for (int i = 0; i < m; i++)
        {
            cin >> e1 >> e2;
            v[e1].push_back(e2);
            v[e2].push_back(e1);
        }

        int t = 0;
        for (int i = 1; i <= n; i++)
        {
            if (visited[i])
                continue;
            if (dfs(i, 0))
                t++;
        }
        if (t == 0)
        {
            cout << "Case " << caseNum << ": No trees.\n";
        }
        else if (t == 1)
        {
            cout << "Case " << caseNum << ": There is one tree.\n";
        }
        else
        {
            cout << "Case " << caseNum << ": A forest of " << t << " trees.\n";
        }
    }
}