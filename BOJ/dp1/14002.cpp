// 2021.09.23 22:17:01
// 14002 https://boj.kr/14002
#include <bits/stdc++.h>
using namespace std;

int dp[1001];
vector<vector<int>> arr(1001);
vector<int> a;
vector<int> f(int pos)
{

    int &ret = dp[pos];
    if (ret)
        return arr[pos];
    
    ret = 1;
    arr[pos].push_back(a[pos]);
    for (int next = pos+1; next < a.size(); next++)
    {
        if (a[pos] < a[next]){
            vector<int> vn = f(next);
            vn.push_back(a[pos]);
            int recur = vn.size();
            if(ret < recur){
                ret = recur;
                arr[pos].clear();
                for(int i=0;i<vn.size();i++){
                    arr[pos].push_back(vn[i]);
                }
            }
        }
    }
    return arr[pos];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a_i;
        cin >> a_i;
        a.push_back(a_i);
    }

    vector<int> ret;
    for (int i = 0; i < n; i++)
    {
        vector<int> next = f(i);
        if(ret.size()< next.size()){
            ret = next;
        }
    }

    cout << ret.size() << '\n';
    for(int i=ret.size()-1;i>=0;i--){
        cout << ret[i] << ' ';
    }
}