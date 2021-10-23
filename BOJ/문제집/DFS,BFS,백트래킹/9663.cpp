// 2021.10.23 18:28:05
// 9663 https://boj.kr/9663
#include <bits/stdc++.h>
using namespace std;
int n;
class Queen
{
public:
    int y, x;
    bool isAttackable(Queen &q2)
    {
        return y == q2.y || x == q2.x || abs(y - q2.y) == abs(x - q2.x);
    }
};
class Board
{
public:
    vector<Queen> queens;
    int queenCount = -1;

    bool isQueenPushable(Queen &newQueen)
    {
        for (auto &queen : queens)
        {
            if (queen.isAttackable(newQueen))
                return false;
        }
        return true;
    }

    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool queenFound = false;
                for (auto &q : queens)
                {
                    if (q.y == i && q.x == j)
                    {
                        cout << "V ";
                        queenFound = true;
                        break;
                    }
                }
                if (!queenFound)
                {
                    cout << "0 ";
                }
            }
            cout << '\n';
        }
        cout << "============\n";
    }
};

int bt(Board &current)
{
    if (current.queens.size() >= n)
    {
        // current.print();
        return 1;
    }

    int sum = 0;
    for (int j = 0; j < n; j++)
    {
        Queen newQueen = {current.queens.size(), j};
        if (current.isQueenPushable(newQueen))
        {
            current.queens.push_back(newQueen);
            sum += bt(current);
            current.queens.pop_back();
        }
    }
    return sum;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;

    Board board;
    cout << bt(board);
}