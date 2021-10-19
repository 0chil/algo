// 2021.10.17 23:39:09
// 13904 https://boj.kr/13904
#include <bits/stdc++.h>
using namespace std;

bool compareAssignments(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int days[1001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, maxDay = 0;
    vector<pair<int, int>> assignments;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int d, w;
        cin >> d >> w;
        assignments.push_back(make_pair(d, w));
        maxDay = max(d, maxDay);
    }

    sort(assignments.begin(), assignments.end(), compareAssignments);

    for (int i = 0; i < n; i++)
    {
        pair<int, int> &thisAss = assignments[i];
        int &exactDay = days[thisAss.first];
        if (exactDay == 0)
        {
            exactDay = thisAss.second;
        }
        else
        {
            for (int before = thisAss.first; before >= 0; before--)
            {
                int &alternativeDay = days[before];
                if (alternativeDay == 0)
                {
                    alternativeDay = thisAss.second;
                    break;
                }
            }
        }
    }

    int total = 0;
    for (int i = 1; i <= maxDay; i++)
    {
        total += days[i];
    }

    cout << total;
}