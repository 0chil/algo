// 2021.07.12 22:30:57
// 2156 http://boj.kr/2156
// 블로그에 리뷰 해야함 - 처음에 푼거 왜틀렸는지.
// (before의 번호가 상관있는건지, 
// 아니면 전에 몇잔을 먹은게 영향을 끼치는 건지 확실히 구분)
#include <bits/stdc++.h>
using namespace std;

int vol[10000];
int dp[10000][3];
int n;

int f(int cur, int cnt)
{
    if (cur >= n)
        return 0;
    int &ret = dp[cur][cnt];
    if (ret != -1)
        return ret;
    //이번꺼 스킵
    int skip = f(cur + 1, 0);
    //이번꺼 마시고 다다음거
    int drinkAndJump = f(cur + 2, 0) + vol[cur];
    //이번꺼 마시고 다음거(가능할경우)
    int drinkAndNext;
    if (cnt == 1)
        drinkAndNext = -1;
    else
        drinkAndNext = f(cur + 1, cnt + 1) + vol[cur];
    return ret = max(drinkAndJump,max(drinkAndNext, skip));
}

int main()
{
    cin >> n;

    for (auto &arr : dp)
        for (auto &num : arr)
            num = -1;

    for (int i = 0; i < n; i++)
        cin >> vol[i];
    cout << f(0, 0);
}