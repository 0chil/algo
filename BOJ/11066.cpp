// 2021.09.26 15:03:06
// 11066 https://boj.kr/11066
#include <bits/stdc++.h>
using namespace std;

vector<int> cost;
int f(int from, int to)
{
    if(from >= cost.size() || to < 0) return 0;
    if(from- to==1) return cost[from]+cost[to];

    int increase_from = f(from+1,to);
    int decrease_to = f(from,to-1);
    return min(increase_from,decrease_to);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cost.clear();
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            int input;
            cin >> input;
            cost.push_back(input);
        }
        cout << f(0,k-1) << " ";

    }
}