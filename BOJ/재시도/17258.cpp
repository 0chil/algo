// 2022.03.16 23:44:27
// 17258 https://boj.kr/17258
#include <bits/stdc++.h>
using namespace std;
int n, m, k, t;
int invitee[301];
int dp[301][301][301];
int neededAmount(int time, int inserted)
{
    return t - (invitee[time] + inserted);
}

bool willFriendsLeave(int time)
{
    return invitee[time] >= t;
}

int f(int time, int inserted, int left)
{
    if (time > n)
        return 0;
    int &ret = dp[time][inserted][left];
    if (ret != -1)
        return ret;
    int total = invitee[time] + inserted;
    int canWookjeJoin = (total >= t);

    if (willFriendsLeave(time + 1))
        inserted = 0;
    int insertNext = INT_MIN;
    int neededNext = neededAmount(time + 1, inserted);
    if (neededNext > 0 && (left - neededNext) >= 0)
        insertNext = f(time + 1, inserted + neededNext, left - neededNext);
    int skipNext = f(time + 1, inserted, left);

    return ret = max(insertNext, skipNext) + canWookjeJoin;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> k >> t;
    for (int i = 0; i < m; i++)
    {
        int arrival, depart;
        cin >> arrival >> depart;
        for (int at = arrival; at < depart; at++)
            invitee[at]++;
    }
    memset(dp, -1, sizeof(dp));
    cout << f(0, 0, k);
}