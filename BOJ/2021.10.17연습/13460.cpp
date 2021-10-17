// 2021.10.17 10:00:10
// 13460 https://boj.kr/13460
#include <bits/stdc++.h>
using namespace std;
#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3

int n, m;
string board[11];
int visited[11][4];
pair<int, int> goal;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, -1, 0, 1};

class Orientation
{
public:
    int orientation, depth;
    pair<int, int> red;
    pair<int, int> blue;
};

void bfs(Orientation start)
{
    queue<Orientation> q;
    q.push(start);

    while (q.size())
    {
        Orientation current = q.front();
        q.pop();

        for (int next = 0; next < 4; next++)
        {
            if (current.orientation == next)
                continue;
            if (current.orientation != -1 && (current.orientation + 2) % 4 == next)
                continue;

            Orientation nextNode = Orientation({next, current.depth + 1});

            pair<int, int> nextRed(current.red);
            pair<int, int> nextBlue(current.blue);
            bool failure = false;
            bool redTouched = false;

            while (true)
            {
                bool redMoved = false, blueMoved = false;
                if (board[nextRed.first + dy[next]][nextRed.second + dx[next]] == '.')
                {
                    nextRed.first += dy[next];
                    nextRed.second += dx[next];
                    redMoved = true;
                }
                else if (board[nextRed.first + dy[next]][nextRed.second + dx[next]] == 'O')
                {
                    nextRed.first += dy[next];
                    nextRed.second += dx[next];
                    redTouched = true;
                    redMoved = true;
                }

                if (board[nextBlue.first + dy[next]][nextBlue.second + dx[next]] == '.')
                {
                    nextBlue.first += dy[next];
                    nextBlue.second += dx[next];
                    blueMoved = true;
                }
                else if (board[nextBlue.first + dy[next]][nextBlue.second + dx[next]] == 'O')
                {
                    failure = true;
                    break;
                }

                if (nextRed.first == nextBlue.first && nextRed.second == nextBlue.second)
                {
                    if (redMoved)
                    {
                        nextRed.first -= dy[next];
                        nextRed.second -= dx[next];
                    }
                    else if (blueMoved)
                    {
                        nextBlue.first -= dy[next];
                        nextBlue.second -= dx[next];
                    }
                    break;
                }

                if (!redMoved && !blueMoved)
                    break;
            }
            if (failure)
                continue;

            if (nextNode.depth == 11)
            {
                continue;
            }

            if (redTouched == true)
            {
                cout << current.depth + 1;
                return;
            }
            nextNode.red = nextRed;
            nextNode.blue = nextBlue;
            q.push(nextNode);
        }
    }
    cout << "-1";
    return;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    char input;
    pair<int, int> red;
    pair<int, int> blue;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> input;

            if (input == 'B')
            {
                blue = make_pair(i, j);
                input = '.';
            }
            if (input == 'R')
            {
                red = make_pair(i, j);
                input = '.';
            }
            if (input == 'O')
            {
                goal = make_pair(i, j);
            }

            board[i].push_back(input);
        }
    }

    bfs(Orientation({-1, 0, red, blue}));
}