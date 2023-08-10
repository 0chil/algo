// 2023.08.10 21:30:06
// 1931 https://boj.kr/1931

// 시간복잡도가 O(n^2) 이므로 DP로는 풀 수 없다.
#include <bits/stdc++.h>
using namespace std;

class meeting
{
public:
    int start;
    int end;
};

int n;
vector<meeting> meetings;

int dp[100'001];

int count(int index)
{
    if (index >= meetings.size())
    {
        return 1;
    }

    auto &ret = dp[index];
    if (ret != -1)
    {
        return dp[index];
    }

    int skip = count(index + 1);
    int use = INT_MIN;
    for (int j = index + 1; j < meetings.size(); j++)
    {
        meeting &current = meetings[index];
        meeting &candidate = meetings[j];
        if (current.end <= candidate.start)
        {
            use = max(use, 1 + count(j));
        }
    }
    return dp[index] = max(use, skip);
}

bool compare(meeting one, meeting other)
{
    if (one.end == other.end)
    {
        return one.start < other.start;
    }
    return one.end < other.end;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        meetings.push_back({start, end});
        dp[i] = -1;
    }
    sort(meetings.begin(), meetings.end(), compare);

    cout << count(0);
}