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
    for (auto [to, limit] : bridge[from])
    {
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
    int left = -1, right = 1e9 + 1; // n + 1로 선언해야 정답 범위에 n이 포함된다
    while (left + 1 < right)
    {
        int mid = (left + right) / 2;
        if (moveable(from, mid))
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
        fill(visited, visited + sizeof(visited), false);
    }
    cout << left;
}