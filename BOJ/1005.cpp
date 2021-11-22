// 2021.11.22 11:10:50
// 1005 https://boj.kr/1005
#include <bits/stdc++.h>
using namespace std;

vector<int> cost;
vector<vector<int> > need(1001,vector<int>());
int w;
int dp[1001];
int f(int building){
    auto& ret = dp[building];
    if(ret != -1) return ret;
     ret = 0;
    for(auto& next : need[building]){
        ret = max(ret, f(next));
    }
    ret += cost[building];
    return ret;
}

void initDp(){
    for(int i=0; i<1001;i++){
        dp[i] = -1;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        for(auto& n : need)
            n.clear();
        cost.clear();
        initDp();
        int n,k, input, input2;
        cin >> n >> k;
        cost.push_back(0);
        for (int i = 0; i < n; i++)
        {
            cin >> input;
            cost.push_back(input);
        }

        for(int i=0;i<k;i++){
            cin >> input >> input2;
            need[input2].push_back(input);
        }
        
        cin >> w;

        cout << f(w) << endl;
    }
}