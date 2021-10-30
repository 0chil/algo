// 2021.10.30 11:32:08
// 13913 https://boj.kr/13913
#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> visited(100002, -1);

bool isInRange(int pos)
{
    return 0 <= pos && pos < 100001;
}

int bfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = 100001;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == k)
        {
            return cur;
        }

        int next[] = {cur - 1, cur + 1, cur * 2};
        for (auto &nextPos : next)
        {
            if (isInRange(nextPos) && visited[nextPos] == -1)
            {
                q.push(nextPos);
                visited[nextPos] = cur;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;

    int lastNode = bfs(n);
    vector<int> answer;
    int depth = 0;
    while (visited[lastNode] != -1)
    {
        answer.push_back(lastNode);
        lastNode = visited[lastNode];
        depth++;
    }

    cout << depth - 1 << '\n';
    while (!answer.empty())
    {
        cout << answer.back() << ' ';
        answer.pop_back();
    }
}