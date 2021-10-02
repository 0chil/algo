// 2021.09.17 19:31:55
// 2004 https://boj.kr/2004
#include <bits/stdc++.h>
using namespace std;

int a_pow_n_cnt(int a, int n){
    int cnt=0;
    while(n >= a){
        cnt += n/a;
        n = n/a;
    }
    return cnt;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    // 100C10 = 100!/10!*90!
    // 상당히 떠올리기 어려운 아이디어였다.
    // https://javabypatel.blogspot.com/2017/05/count-trailing-zeros-in-factorial-of-number.html
    int cnt_2 = 0, cnt_5 = 0;

    cnt_2 = a_pow_n_cnt(2,n) -a_pow_n_cnt(2,n-m) - a_pow_n_cnt(2,m);
    cnt_5 = a_pow_n_cnt(5,n) -a_pow_n_cnt(5,n-m) - a_pow_n_cnt(5,m);

    cout << min(cnt_2, cnt_5);
}