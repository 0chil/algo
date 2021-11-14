// 2021.11.15 00:17:54
// 11725 https://boj.kr/11725
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> vertices;
int n;
int visited[100001];
int parentOf[100001];
void dfs(int currentNode)
{
    visited[currentNode] = 1;

    for (auto &edge : vertices[currentNode])
    {
        if (!visited[edge])
        {
            parentOf[edge] = currentNode;
            dfs(edge);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    vertices = vector<vector<int>>(n + 1, vector<int>());

    for (int i = 1; i < n; i++)
    {
        int e1, e2;
        cin >> e1 >> e2;
        vertices[e1].push_back(e2);
        vertices[e2].push_back(e1);
    }

    dfs(1);

    for(int i=2;i<=n;i++){
        cout << parentOf[i] << '\n';
    }
}