// 2023.08.11 09:56:13
// 12865_2 https://boj.kr/12865_2
#include <bits/stdc++.h>
using namespace std;

class object
{
public:
    int weight, value;
};

int n, k;
vector<object> objects;
int dp[101][100'001];

int total(int index, int weight)
{
    if (index >= objects.size())
    {
        return 0;
    }
    auto &ret = dp[index][weight];
    if (ret != -1)
    {
        return ret;
    }

    auto &currentObject = objects[index];
    int skip = total(index + 1, weight);
    int use = INT_MIN;
    if (weight + currentObject.weight <= k)
    {
        use = total(index + 1, weight + currentObject.weight) + currentObject.value;
    }
    return ret = max(skip, use);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int weight, value;
        cin >> weight >> value;
        objects.push_back({weight, value});
    }
    memset(dp, -1, sizeof(dp));

    cout << total(0, 0);
}