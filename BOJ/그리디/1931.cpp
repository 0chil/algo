// 2023.08.06 23:51:02
// 1931 https://boj.kr/1931
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> schedules;

bool ends_faster(const pair<int, int> one, const pair<int, int> other)
{
    if (one.second == other.second)
    {
        return one.first < other.first;
    }
    return one.second < other.second;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        schedules.push_back(make_pair(start, end));
    }

    sort(schedules.begin(), schedules.end(), ends_faster);

    int count = 0;
    int now = 0;
    for (auto &schedule : schedules)
    {
        if (now <= schedule.first)
        {
            now = schedule.second;
            count++;
        }
    }

    cout << count;
}