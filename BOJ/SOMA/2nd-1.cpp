// 2022.03.19 20:33:47
// 2nd-1 https://boj.kr/2nd-1
#include <bits/stdc++.h>
using namespace std;

/**
 * 4 3 2 9 4 3 8 2 4 4 4 5 5 7 3
 *
 *
 */

int n, m, k;
int fav[100001][17];

bool willLeave(int mi, int ci)
{
    for (int i = mi + 1; i < m; i++)
    {
        if (fav[ci][i] >= 5)
            return false;
    }
    if (fav[ci][mi] >= 5)
        return false;
    else
        return true;
}

int f(int mi, int kleft)
{
    if (mi >= m && kleft == 0)
        return 0;
    if(mi >= m || kleft < 0)
        return 987654321;
    int leaveWhenSkipThis = 0;
    for (int i = 0; i < n; i++)
    {
        leaveWhenSkipThis += willLeave(mi, i);
    }

    int removeThis = f(mi + 1, kleft - 1) + leaveWhenSkipThis;
    int skipThis = f(mi + 1, kleft);

    return min(removeThis, skipThis);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> fav[i][j];
        }
    }
    cout << f(0,m);
    // cout << willLeave(0);
}