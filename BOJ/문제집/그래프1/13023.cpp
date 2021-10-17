// 2021.10.14 22:17:22
// 13023 https://boj.kr/13023
#include <bits/stdc++.h>
using namespace std;

bool visited[2001];
vector<vector<int>> r(2001);
int n, m;

bool isFriendDepth(int cur, int depth)
{
    if (depth == 4)
        return true;

    visited[cur] = true;
    bool ret = false;
    //find cur.a -> someone
    for (int i = 0; i < r[cur].size(); i++)
    {
        int nextNode = r[cur][i];
        if (!visited[nextNode])
        {
            if (isFriendDepth(nextNode, depth + 1))
            {
                ret = true;
                break;
            }
        }
    }
    visited[cur] = false;
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int inp1, inp2;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> inp1 >> inp2;
        r[inp1].push_back(inp2);
        r[inp2].push_back(inp1);
    }

    for (int i = 0; i < n; i++)
    {
        if (isFriendDepth(i, 0) == true)
        {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    return 0;
}