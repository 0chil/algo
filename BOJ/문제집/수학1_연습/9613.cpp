// 2021.09.17 22:26:49
// 9613 https://boj.kr/9613
#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        long long sum=0;
        int n;
        cin >> n;
        vector<int> num;
        for(int i=0;i<n;i++){
            int temp;
            cin >> temp;
            num.push_back(temp);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(num[i] > num[j])
                    sum+=gcd(num[i],num[j]);
                else{
                    sum+=gcd(num[j],num[i]);
                }
            }
        }
        cout << sum << '\n';
    }

}