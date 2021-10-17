// 2021.10.05 22:21:39
// 9205 https://boj.kr/9205
#include <bits/stdc++.h>
using namespace std;

class Point
{
public:
    int y, x;

    bool isReachable(const Point &other)
    {
        return this->diff(other) <= 1000;
    }

    int diff(const Point &other)
    {
        return abs(this->y - other.y) + abs(this->x - other.x);
    }
};

int visited[101];
int n;
vector<Point> nodes;

void bfs(Point start)
{
    queue<Point> q;
    q.push(start);
    // start.setVisited(true);

    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();

        for (int next = 0; next <= n; next++)
        {
            Point nextNode = nodes[next];
            if (!visited[next] && nextNode.isReachable(cur)){
                visited[next] = 1;
                q.push(nextNode);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        nodes.clear();
        Point start;
        cin >> n >> start.y >> start.x;
        for (int i = 0; i <= n; i++)
        {
            Point convini;
            cin >> convini.y >> convini.x;
            nodes.push_back(convini);
        }

        bfs(start);
        if (visited[n])
        {
            cout << "happy\n";
        }
        else{
            cout << "sad\n";
        }

        for(int i=0;i<=n;i++){
            visited[i] = 0;
        }
    }
}