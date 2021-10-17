// 2021.10.02 22:05:58
// 5014 https://boj.kr/5014
#include <bits/stdc++.h>
using namespace std;
int f, s, g, u, d;

int visited[1000001];
class Node
{
public:
    int floor, depth;
    void visit()
    {
        visited[floor] = 1;
    }
};

bool isValid(int floor)
{
    return floor >= 1 && floor <= f;
}

int bfs(int start)
{
    queue<Node> q;
    q.push(Node({start, 0}));
    int answer = 987654321;
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        if (cur.floor == g)
        {
            answer = min(answer, cur.depth);
            continue;
        }

        if (isValid(cur.floor + u) && !visited[cur.floor + u])
        {
            Node up = Node({cur.floor + u, cur.depth + 1});
            q.push(up);
            up.visit();
        }
        if (isValid(cur.floor - d) && !visited[cur.floor - d])
        {
            Node down = Node({cur.floor - d, cur.depth + 1});
            q.push(down);
            down.visit();
        }
    }
    return answer;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> f >> s >> g >> u >> d;
    int answer = bfs(s);
    if (answer == 987654321)
        cout << "use the stairs";
    else
        cout << answer;
}