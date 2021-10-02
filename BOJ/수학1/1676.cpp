// 2021.09.14 23:45:08
// 1676 https://boj.kr/1676
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    // 10 10*9*8*7*6*5*4*3*2*1
    int cnt_2 = 0;
    int cnt_5 = 0;
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        int obj = i;
        while(obj % 5 == 0){
            obj = obj/5;
            cnt_5++;
        }
        while (obj % 2 == 0){
            obj = obj/2;
            cnt_2++;
        }
    }

    for (int i = 0; i < cnt_2; i++)
    {
        if (cnt_5-- > 0)
            ans++;
    }

    cout << ans;
}