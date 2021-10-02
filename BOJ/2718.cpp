// 2021.07.05 23:15:26
// 2718 http://boj.kr/2718

//  다시 풀어야겠다. 
// N은 타일을 채우는 경우의 수가 2,147,483,647 이하이도록 주어진다.
// 이 말 때문에 비트마스킹이 필요(배열로는 불가능)
// 그리고 점화식이 틀린 이유는 N=3 인경우 
/*
    ==|
    |== 이런경우가 가능하므로 
    
    단순히 1씩 늘어나는 경우, 2씩 늘어나는 경우가 아니라 전부다 세줘야 한다.

*/
#include <bits/stdc++.h>
using namespace std;

int cache[1000000];
int n;
int dp(int i){
    int& ret = cache[i];
    if(ret != -1) return ret;
    if(i >= n) return 0;
    if(i==n-1) return 1;
    return ret = (dp(i+1) + 4*dp(i+2));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for(int& num : cache){
            num = -1;
        }
        cout << dp(0);
    }
}