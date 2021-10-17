// 2021.10.01 14:03:46
// 7569 https://boj.kr/7569
#include <bits/stdc++.h>
using namespace std;

const int dz[6] = {1, -1, 0, 0, 0, 0};
const int dy[6] = {0, 0, 1, -1, 0, 0};
const int dx[6] = {0, 0, 0, 0, 1, -1};

int box[101][101][101];
int n, m, h;

class Node
{
public:
    int z, y, x, day;

    void ripe()
    {
        box[z][y][x] = 1;
    }

    bool isValid()
    {
        return this->z >= 0 && this->z < h && this->y >= 0 && this->y < n && this->x >= 0 && this->x < m;
    }
};


int bfs(vector<Node> &startNodes)
{
    queue<Node> q;
    for (auto &node : startNodes)
    {
        q.push(node);
    }

    int day = 0;
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        day = max(day, cur.day); 
        /* 가능한 깊이까지 내려간 것을 골라야함. (이게 끝이다.)
         BFS를 사용한 순간부터 이미 최소값을 구하게 된다. 
         (방문한 곳은 다시 방문하지 않으므로 이미 경로가 최소가 됨)
         이것 때문에 많이 고민했다.
         최솟값 찾으라 했더니 최대값을 찾고 있다고 거부감 가지지 말것. */

        for (int next = 0; next < 6; next++)
        {
            Node nextNode = Node({cur.z + dz[next], cur.y + dy[next], cur.x + dx[next], cur.day + 1});
            if (nextNode.isValid() && box[nextNode.z][nextNode.y][nextNode.x] == 0)
            {
                q.push(nextNode);
                nextNode.ripe();
            }
        }
    }

    return day;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> m >> n >> h;

    vector<Node> startNodes;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1)
                {
                    startNodes.push_back(Node({i, j, k, 0}));
                }
            }
        }
    }

    int answer = bfs(startNodes);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (box[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << answer;
}