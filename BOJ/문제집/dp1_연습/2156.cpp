// 2021.09.18 23:30:57
// 2156 https://boj.kr/2156
#include <bits/stdc++.h>
using namespace std;

int dp[10001][3];
vector<int> vol;
int f(int n, int cnt){
    if(n<=0) return 0;
    int &ret = dp[n][cnt];
    if(ret!=-1) return ret;
    int notdrink=f(n-1,0);
    if(cnt==2) return ret = notdrink;
    int drink = f(n-1,cnt+1)+vol[n-1];
    return ret = max(drink,notdrink);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int vol_i;
        cin >> vol_i;
        vol.push_back(vol_i);
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<3;j++){
            dp[i][j] = -1;
        }
    }
    cout << f(n,0);

}