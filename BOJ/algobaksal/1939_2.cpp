// 2023.09.16 12:54:32
// 1939 https://boj.kr/1939
#include <bits/stdc++.h>
using namespace std;

int n, m, from, destination;
vector<pair<int, int>> bridge[10001];
bool visited[10001];

bool moveable(int from, int weight)
{
    if (from == destination)
    {
        return true;
    }
    visited[from] = true;
    for (auto &node : bridge[from])
    {
        int to = node.first;
        int limit = node.second;
        if (!visited[to] && weight <= limit && moveable(to, weight))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        bridge[a].push_back({b, c});
        bridge[b].push_back({a, c});
    }
    cin >> from >> destination;
    int max = 0;
    int left = 0, mid, right = 1e9;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (moveable(from, mid))
        {
            max = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
        fill(visited, visited + sizeof(visited), false);
    }
    cout << max;
}