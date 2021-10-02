// 2021.10.01 13:10:33
// 1260 https://boj.kr/1260
#include <bits/stdc++.h>
using namespace std;

int n;
int graph[1001][1001];
int visited[1001];

void dfs(int currentNode){
    cout << currentNode << ' ';
    visited[currentNode] = 1;

    for(int next=1;next<=n;next++){
        if(!visited[next] && graph[currentNode][next]){
            dfs(next); 
        }
    } 
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] =1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for(int next=1;next<=n;next++){
            if(!visited[next] && graph[cur][next]){
                q.push(next);
                visited[next] = 1;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m, v;
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from][to] = graph[to][from] = 1;
    }

    //DFS
    for(int i=0;i<=n;i++)
        visited[i] = 0;
    dfs(v);
    
    cout << '\n';
    //BFS
    for(int i=0;i<=n;i++)
        visited[i] = 0;
    bfs(v);

}