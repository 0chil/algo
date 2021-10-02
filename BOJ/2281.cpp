// 2021.07.05 23:14:49
// 2281 http://boj.kr/2281
#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
int length[1000];
int n, m;

int powBlank(int col)
{
    return (m - col + 1) * (m - col + 1);
}

int f(int person, int col)
{
    if(person >= n) return 0;
    int &ret = dp[person][col];
    if (ret != -1)
        return ret;
    int noNewLine = f(person + 1, col + length[person] + 1);
    int newLine = f(person + 1, length[person] + 1) + powBlank(col);
    if(length[person] > m - col)
        return ret = newLine;
    return ret = min(noNewLine,newLine);
}

int main()
{
    cin >> n >> m;

    for (auto &arr : dp)
        for (auto &num : arr)
            num = -1;

    for (int i = 0; i < n; i++)
        cin >> length[i];

    cout << f(0, 0);
}