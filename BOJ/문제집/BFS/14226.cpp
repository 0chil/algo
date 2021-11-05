// 2021.11.05 18:13:43
// 14226 https://boj.kr/14226
#include <bits/stdc++.h>
using namespace std;
#define BFS
int s;

#ifdef DP
int dp[1001][1001];
int f(int emoCount, int clipboard)
{
    if (emoCount > 1000 || emoCount < 1)
        return 987654321;
    if (emoCount == s)
        return 0;
    int &ret = dp[emoCount][clipboard];
    if (ret != -1)
        return ret;

    ret = 1001;
    int arr[3][2] = {{emoCount, emoCount}, {emoCount + clipboard, clipboard}, {emoCount - 1, clipboard}};
    for (int i = 0; i < 3; i++)
    {
        ret = min(ret, f(arr[i][0], arr[i][1]) + 1);
    }
    return ret;
}
#endif

#ifdef BFS
int visited[2001][2001];
class Node
{
public:
    int emoCount, clipboard, time;
    bool isVisited()
    {
        return visited[emoCount][clipboard] == 1;
    }
};

int bfs()
{
    queue<Node> q;
    q.push({1, 0, 0});
    visited[1][0] = 1;
    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();
        if (cur.emoCount < 1 || cur.emoCount > 1000 || cur.clipboard > 1000)
            continue;
        else if (cur.emoCount == s)
        {
            return cur.time;
        }

        Node nodes[3] = {
            {cur.emoCount, cur.emoCount, cur.time + 1},
            {cur.emoCount + cur.clipboard, cur.clipboard, cur.time + 1},
            {cur.emoCount - 1, cur.clipboard, cur.time + 1}};

        for (int i = 0; i < 3; i++)
        {
            Node next = nodes[i];
            if(i==0 && next.clipboard == cur.clipboard) continue;
            if(i==1 && cur.emoCount == 0) continue;
            if (!next.isVisited())
            {
                visited[next.emoCount][next.clipboard] = true;
                q.push(next);
            }
        }
    }
}
#endif

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> s;
#ifdef BFS
    cout << bfs();
#endif

#ifdef DP
    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            dp[i][j] = -1;
        }
    }
    cout << f(1, 0);
#endif
}