// 2021.10.21 22:21:24
// 2343 https://boj.kr/2343
#include <bits/stdc++.h>
using namespace std;
vector<int> lesson;
int n, m;

bool checkPossible(int bluerayLength)
{
    int diskSum = 0;
    int seperationCount = 0;
    for (int i = 0; i < n; i++)
    {
        // 레슨 하나를 담을수가 없다.
        if (bluerayLength < lesson[i])
            return false;
        if (diskSum + lesson[i] > bluerayLength)
        {
            seperationCount++;
            // 이 레슨부터는 다음 디스크에 담음
            diskSum = lesson[i];
            if (seperationCount > m - 1) // 디스크 수가 초과하면 끝.
                return false;
            continue;
        }
        // 괜찮으면 디스크에 담는다.
        diskSum += lesson[i];
    }
    return true;
}

int bs(int left, int right)
{
    if (left > right)
        return 1e9;
    int mid = (left + right) / 2;
    //내가 중간으로 정해봤어. 여기다 담을수 있냐?
    if (checkPossible(mid))
    {
        //ㅇㅇ 담을수 있음 -> 그럼 더 줄여볼게 이것도 해봐
        return min(mid,bs(left, mid - 1));
    }
    else
    {
        // 미안 이것 안될것같다 -> 그래? 그럼 좀 늘려볼게
        return bs(mid + 1, right);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int input;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        lesson.push_back(input);
    }

    cout << bs(0, 1e9);
}