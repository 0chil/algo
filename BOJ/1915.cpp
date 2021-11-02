// 2021.11.01 16:47:56
// 1915 https://boj.kr/1915
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001];
const int dy[] = {1, 0, 1};
const int dx[] = {0, 1, 1};

void initDp(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dp[i][j] = -1;
        }
    }
}

int f(int y, int x)
{
    if (arr[y][x] == 0)
        return 0;
    if(y==n-1 || x == m-1) return 1;
    int& ret = dp[y][x];
    if(ret != -1) return ret;

    ret = 1001;
    for (int next = 0; next < 3; next++)
    {
        //3개 다 1이어야 길이에 추가
        int ny = y + dy[next];
        int nx = x + dx[next];

        ret = min(ret, f(ny, nx)+1);
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin>> s;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = s[j]-'0';
        }
    }
    
    initDp();

    int maxLength=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maxLength = max(maxLength, f(i,j));
        }
    }
    cout << maxLength*maxLength;
}