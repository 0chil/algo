// 2021.12.30 12:31:11
// 4963 https://boj.kr/4963
#include <bits/stdc++.h>
#define LAND 1
#define VISITED 2

using namespace std;
const int dy[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int Map[51][51];
int w, h;

class Loc
{
public:
    int y, x;

    bool isVisited()
    {
        if (Map[y][x] == VISITED)
            return true;
        return false;
    }

    void visit(){
        Map[y][x] = VISITED;
    }

    bool isValid()
    {
        return 0 <= y && y < h && 0 <= x && x < w && Map[y][x] == LAND;
    }
};

void bfs(int sy, int sx)
{
    queue<Loc> q;
    Map[sy][sx] = VISITED;
    q.push({sy, sx});

    while (!q.empty())
    {
        Loc cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            Loc next = {cur.y + dy[i], cur.x + dx[i]};
            if(next.isValid() && !next.isVisited()){
                q.push(next);
                next.visit();
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            return 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> Map[i][j];

        int count = 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (Map[i][j] == LAND){
                    bfs(i,j);
                    ++count;
                }
        cout << count << '\n';
    }
}