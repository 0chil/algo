// 2021.10.10 14:39:36
// 16735 https://boj.kr/16735
#include <bits/stdc++.h>
using namespace std;
#define six_thirty 390
#define ten 600
#define sixteen 960
#define nineteen 1140
class Time
{
public:
    int min;
    int toMinute()
    {
        return min;
    }

    bool isValid()
    {
        return 390 <= toMinute() && toMinute() <= 1140;
    }
};

bool timeComparison(Time t1, Time t2)
{
    return t1.toMinute() < t2.toMinute();
}

int charge(Time &firstSeen, Time &lastSeen)
{
    if (six_thirty <= firstSeen.toMinute() && firstSeen.toMinute() <= ten)
    {
        if (six_thirty <= lastSeen.toMinute() && lastSeen.toMinute() <= sixteen)
        {
            return 24000;
        }
        else if (sixteen+1<= lastSeen.toMinute() && lastSeen.toMinute() <= nineteen)
        {
            return 36000;
        }
    }
    if (ten+1 <= firstSeen.toMinute() && firstSeen.toMinute() <= sixteen)
    {
        if (ten+1 <= lastSeen.toMinute() && lastSeen.toMinute() <= sixteen)
        {
            return 16800;
        }
    }
    if (ten+1 <= firstSeen.toMinute() && firstSeen.toMinute() <= nineteen)
    {
        if (sixteen+1 <= lastSeen.toMinute() && lastSeen.toMinute() <= nineteen)
        {
            return 24000;
        }
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<Time> seen;

    for (int i = 0; i < n; i++)
    {

        int h, m;
        scanf("%d:%d", &h, &m);
        Time t = Time({h * 60 + m});
        if (t.isValid())
        {
            seen.push_back(t);
        }
    }

    if (!seen.size())
    {
        cout << 0;
        return 0;
    }

    sort(seen.begin(), seen.end(), timeComparison);
    printf("%d", charge(seen[0], seen[seen.size() - 1]));
}