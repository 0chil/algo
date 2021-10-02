// 2021.09.18 23:09:36
// 9465 https://boj.kr/9465
#include <bits/stdc++.h>
using namespace std;

int dp[100001][3];
vector<vector<int> > score;
int f(int n,int sticker){
    if(n==0) return 0;
    int &ret = dp[n][sticker];
    if(ret!=-1) return ret;
    ret =0;
    for(int next_sticker=0;next_sticker<3;next_sticker++){
        if(sticker && sticker == next_sticker) continue;
        ret = max(ret,f(n-1,next_sticker)+score[sticker][n-1]);
    }
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        score.clear();
        int n;
        cin >> n;
        score.push_back(vector<int>(n,0));
        for(int i=0;i<2;i++){
            vector<int> scorei;
            for(int j=0;j<n;j++){
                int scoreij;
                cin>> scoreij;
                scorei.push_back(scoreij);
            }
            score.push_back(scorei);
        }

        for(int i=0;i<=n;i++){
            for(int j=0;j<3;j++){
                dp[i][j] = -1;
            }
        }

        cout << max(max(f(n,0),f(n,1)),f(n,2)) << '\n';
    }
}