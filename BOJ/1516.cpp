// 2021.11.22 21:21:43
// 1516 https://boj.kr/1516
#include <bits/stdc++.h>
using namespace std;
vector<int> cost(501,0);
vector<vector<int> > needed(501,vector<int>());
int dp[501];
int f(int building){
    auto& ret = dp[building];
    if(ret) return ret;

    for(auto& next : needed[building]){
        ret = max(ret, f(next));
    }
    ret += cost[building];
    return ret;

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    for(int i=1;i<=n;i++){
        int c, input;
        cin >> c;
        cost[i] = c;
        while((cin >> input) && input != -1){
            needed[i].push_back(input);
        }
    }

    for(int i=1;i<=n;i++){
        cout << f(i) << endl;
    }
}