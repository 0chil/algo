// 2021.10.15 22:02:25
// 17258 https://boj.kr/17258
#include <bits/stdc++.h>
using namespace std;

int n, m, k, t;
int friends[301];
int dp[301][301][301];
// 욱제가 파티에 머무는 시간 (최대)
int f(int time, int yeongsunFriends, int yfLeft)
{
    if (time > n)
        return 0;

    int &ret = dp[time][yeongsunFriends][yfLeft];
    if(ret) return ret;

    int friendsNow = friends[time];
    bool canWookjeJoinThis = (friendsNow + yeongsunFriends) >= t;

    int friendsNext = friends[time+1];
    if (friendsNext >= t)
        yeongsunFriends = 0;
    int yfNeeded = t - (friendsNext + yeongsunFriends);

    int joinYeongsunFriendsNext = 0;
    if (yfNeeded > 0 && yfLeft >= yfNeeded)
    {
        joinYeongsunFriendsNext = f(time + 1, yeongsunFriends + yfNeeded, yfLeft - yfNeeded) + canWookjeJoinThis;
    }
    int notJoinYf = f(time + 1, yeongsunFriends, yfLeft) + canWookjeJoinThis;
    return ret = max(joinYeongsunFriendsNext, notJoinYf);
}

/* // 인원이 t 이상 채워지는 시간
int f(int time){

    // 1. 영선이 친구들 수가 부족한 수 이상이면 투입.
    // 2. 아예 투입하지 않는다.
} */

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k >> t;
    for (int i = 0; i < m; i++)
    {
        int ai, bi;
        cin >> ai >> bi;
        for(int i=ai;i<bi;i++){
            ++friends[i];
        }
    }

    cout << f(0, 0, k);
}