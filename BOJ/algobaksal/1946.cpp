// 2023.09.16 04:19:58
// 1946 https://boj.kr/1946
#include <bits/stdc++.h>
using namespace std;

class Person
{
public:
    int paperOrder;
    int interviewOrder;

    bool isInterviewBetterThan(Person &other)
    {
        return this->interviewOrder < other.interviewOrder;
    }
};

bool comparePaper(Person &a, Person &b)
{
    return a.paperOrder < b.paperOrder;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        vector<Person> people;

        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int paperOrder, interviewOrder;
            cin >> paperOrder >> interviewOrder;
            people.push_back({paperOrder, interviewOrder});
        }

        sort(people.begin(), people.end(), comparePaper);

        int cut = 1;
        auto &lastWinner = people[0];
        for (int i = 1; i < n; i++)
        {
            auto &person = people[i];
            if (person.isInterviewBetterThan(lastWinner))
            {
                cut++;
                lastWinner = person;
            }
        }
        cout << cut << '\n';
    }
}
/*
15, 9 일단 합격시켜 9점 기준 높은애 합격
14, 8 ㄴ
13, 7 ㄴ
12, 1ㄴ
11, 5ㄴ
10, 4ㄴ
9, 2ㄴ
8, 3ㄴ
7, 6ㄴ
6, 10 ㅇㅇ 이제 얘기준
5, 11 ㅇㅇ 얘기준
4, 15 ㅇㅇ 얘기준
3, 14 ㄴㄴ
2, 13 ㄴ
1, 12 ㄴ


5, 1 ㅇㅇ
4, 5 ㅇㅇ
3, 4 ㄴ
2, 3 ㄴ
1, 2 ㄴ
 */