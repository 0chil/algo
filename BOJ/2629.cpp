// 2021.09.26 13:42:55
// 2629 https://boj.kr/2629
#include <bits/stdc++.h>
using namespace std;
vector<int> weight, ball;
int dp[15001][31];

int ballweight;
int f(int weightsum, int widx)
{
    if (weightsum == ballweight)
        return 0;
    if (widx >= weight.size())
        return 1;
    int &ret = dp[weightsum][widx];
    if (ret != -1)
        return ret;
    int l = f(weightsum + weight[widx], widx + 1);
    int n = f(weightsum, widx + 1);
    int r = f(abs(weightsum - weight[widx]), widx + 1);

    ret = (l && n && r);
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int wn, bn, input;
    cin >> wn;
    for (int i = 0; i < wn; i++)
    {
        cin >> input;
        weight.push_back(input);
    }
    cin >> bn;

    for (int i = 0; i < bn; i++)
    {
        for (auto &arr : dp)
            for (auto &num : arr)
                num = -1;
        cin >> ballweight;
        cout << ((f(0, 0) == 0) ? "Y " : "N ");
    }
}