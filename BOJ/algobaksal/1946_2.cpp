// 2023.09.16 04:19:58
// 1946 https://boj.kr/1946
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    return a.first > b.first;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    // int t;
    // cin >> t;
    // while (t--)
    // {

        vector<pair<int, int>> people;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int paper, interview;
            cin >> paper >> interview;
            people.push_back({paper, interview});
        }
        sort(people.begin(), people.end(), compare);

        cout << endl;
        int out = 0;
        for (int i = 0; i < people.size(); i++)
        {
            auto &person = people[i];
            bool noBetter = false;
            for (int j = i + 1; j < people.size(); j++)
            {
                auto &rival = people[j];
                if (person.second >= rival.second)
                {
                    noBetter = true;
                    break;
                }
            }
            if (noBetter)
            {
                out++;
                cout << person.first << ", " << person.second << "\n";
            }
        }
        cout << n - out;
    // }
}
/**
 * 3 4 A
 * 1 2 B
 * 4 5 C
 * 2 3 D
 * 5 1 E
 *
 * 5 1 E 4 5 C
 * 4 5 C 3 4 A
 * 3 4 A 2 3 D
 * 2 3 D 1 2 B
 * 1 2 B 5 1 E
 * B 위 ACDE, E는 이겼네
 * D 위 ACE, E는 이겼네
 * A 위 CE, E는 이겼네
 * C 위 E, E는 이겼네
 * E 위 없음, 누구하나라도 이겨야 하는데 없네.
 * 4명
 */