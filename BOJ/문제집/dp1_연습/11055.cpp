// 2021.10.05 22:54:45
// 11055 https://boj.kr/11055
#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int dp[1001];

// 현재부터 끝까지의 증가 부분 수열 합
int f(int pos)
{

    int &ret = dp[pos];
    if (ret)
        return ret;
    ret = a[pos];
    for (int next = pos + 1; next < a.size(); next++)
    {
        if(a[pos] < a[next]){
            ret = max(ret, f(next) + a[pos]);
        }
    }

    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, input;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        a.push_back(input);
    }

    int ret = 0;
    for(int i=0;i<n;i++){
        ret = max(ret, f(i));
    }
    cout << ret;
}