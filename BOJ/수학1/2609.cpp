// 2021.09.13 19:22:57
// 2609 https://boj.kr/2609
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    int GCD, LCM;
    if(a>b){
        GCD = gcd(a,b);
    }
    else{
        GCD = gcd(b,a);
    }
    LCM = a*b/GCD;
    cout << GCD << '\n' << LCM;
}