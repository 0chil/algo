// 2021.09.14 22:53:57
// 1929 https://boj.kr/1929
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    vector<bool> prime(1000001, true);

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                //i*i 부터 시작하는 이유: 기존것은 이미 처리 되어있음.
                prime[j] = false;
            }
        }
    }

    for(int i=m;i<=n;i++){
        if(i!=1 && prime[i]){
            cout << i << '\n';
        }
    }
}