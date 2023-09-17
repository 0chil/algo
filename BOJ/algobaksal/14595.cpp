// 2023.09.17 19:18:25
// 14595 https://boj.kr/14595
#include <bits/stdc++.h>
using namespace std;

int parent[1'000'001];

int getParentOf(int room)
{
    if (parent[room] == room)
    {
        return room;
    }
    return parent[room] = getParentOf(parent[room]);
}

void unionRoom(int room, int other)
{
    room = getParentOf(room);
    other = getParentOf(other);
    if (room == other)
    {
        return; // 이미 부모같으면 스킵
    }
    if (room < other)
    {
        parent[other] = room;
        return;
    }
    parent[room] = other;
}

vector<pair<int, int>> ranges;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; i++) // 최악 5'000
    {
        int x, y;
        cin >> x >> y;
        ranges.push_back({x, y});
    }
    sort(ranges.begin(), ranges.end());

    int right = 0;
    for (int i = 0; i < m; i++) // 최악 5'000
    {
        auto [x,y] = ranges[i];
        for (int j = max(right, x + 1); j <= y; j++)
        {
            unionRoom(x, j);
            // 메모리에서 바로 긁어온다 해도, 대입 작업이 한번은 들어감
            // 5'000'000'000 50억..? 시간초관데.. 스킵 불가?
            // 한번 부순방 다시 부술필요 없음. 스킵.
            // 앞에 안부순 방이 있을수도 있는데 뒤까지 스킵하면 안됨 -> 정렬 필요
            // 부수는 순서는 상관 없음. 정렬해도 됨
        }
        right = max(right, y);
    }

    int count = 0;
    int prev = 0;
    for (int i = 1; i <= n; i++)
    {
        auto parent = getParentOf(i);
        if (parent != prev)
        {
            count++;
            prev = parent;
        }
    }

    cout << count;
}