// 2021.10.01 11:47:58
// 2606 https://boj.kr/2606
#include <bits/stdc++.h>
using namespace std;

int graph[101][101];
bool visited[101];
int n;
int dfs(int currentNode)
{
    int infected=1;
    visited[currentNode] = 1;
    for (int next = 1; next <= n; next++)
    {
        if (!visited[next] && graph[currentNode][next])
        {
            infected+=dfs(next);
        }
    }
    return infected;
}

int bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    int infected=0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int next=1;next<=n;next++){
            if(!visited[next] && graph[cur][next]){
                visited[next] = 1;
                q.push(next);
                infected++;
            }
        }
    }
    return infected;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int m; cin>> m;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from][to] = graph[to][from] = 1;
    }
    // cout << dfs(1) - 1;
    cout << bfs(1);
}