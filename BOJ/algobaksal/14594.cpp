// 2023.09.16 03:00:44
// 14594 https://boj.kr/14594
#include <bits/stdc++.h>
using namespace std;

int room[101];

int n, m;
void propagate(int position, int number)
{
    int criteria = room[position];
    for (int i = position; i <= n; i++)
    {
        if(room[i] == criteria){
            room[i] = number;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    for (int i = 1; i <= 100; i++)
    {
        room[i] = i;
    }
    cin >> n >> m;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        for (int i = x + 1; i <= y; i++)
        {
            propagate(i, room[i-1]);
            // room[i] = room[i - 1];
        }
    }

    int prev = room[1], count = 1;
    for (int i = 2; i <= n; i++)
    {
        if (room[i] != prev)
        {
            count++;
            prev = room[i];
        }
    }
    cout << count;
}