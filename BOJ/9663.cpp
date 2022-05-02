// 2022.05.02 15:31:37
// 9663 https://boj.kr/9663
#include <bits/stdc++.h>
using namespace std;

int n;
class Queen
{
public:
    int y, x;
    bool isAttackable(const Queen &q2)
    {
        return y == q2.y || x == q2.x || abs(y - q2.y) == abs(x - q2.x);
    }
};

class Board
{
public:
    vector<Queen> queens;

    bool isPushable(const Queen &q2)
    {
        for (Queen& q : queens)
        {
            if (q.isAttackable(q2))
                return false;
        }
        return true;
    }
};

int bt(Board &board)
{
    int i = board.queens.size();
    if (i == n)
        return 1;

    int ret = 0;
    for (int j = 0; j < n; j++)
    {
        Queen q2 = {i, j};
        if (board.isPushable(q2))
        {
            board.queens.push_back(q2);
            ret += bt(board);
            board.queens.pop_back();
        }
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    
    Board board;
    cout << bt(board);
}