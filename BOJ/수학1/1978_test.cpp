// 2021.09.14 22:14:09
// 1978 https://boj.kr/1978
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >>n;
    vector<int> v;
    vector<bool> prime(1000,true);
    int max_given = 0;
    while(n--){
        int given;
        cin >> given;
        max_given=max(max_given,given);
        v.push_back(given);
    }

    for(int i=2;i*i<=max_given; i++){
        if(prime[i] == true){
            for(int j=i*i; j<=max_given;j+=i){ 
                //i*i 부터 시작하는 이유: 기존것은 이미 처리 되어있음.
                prime[j] = false;
            }
        }
    }

    int prime_cnt=0;
    for(int i=0;i<v.size();i++){
        if(prime[v[i]] && i!=1){
            prime_cnt++;
        }
    }
    cout << prime_cnt;
}