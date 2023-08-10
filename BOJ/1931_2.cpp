// 2023.08.11 00:58:06
// 1931 https://boj.kr/1931

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

bool compare(meeting one, meeting other)
{
    if (one.end == other.end)
    {
        return one.start < other.start;
    }
    return one.end < other.end;
}

void print(meeting &meeting)
{
    for (int i = 0; i < meeting.start; i++)
    {
        cout << " ";
    }
    for (int i = meeting.start; i <= meeting.end; i++)
    {
        cout << "-";
    }
    cout << endl;
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
    }
    sort(meetings.begin(), meetings.end(), compare);

    int time = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        // 시간은 역행할 수 없기 때문에 빨리 끝나는 회의로 정렬하면 가능한 회의가 시간순으로 정렬된다.
        // 그래서 빨리 끝나는 회의만 선택하면 최적임은 알겠다.
        // 그러나 시작 시간으로 인해 먼저 진행할 수 있는 회의를 놓칠 가능성은 없는가?

        // 끝이 같으면, 시작이 빠른 순으로 정렬할 필요가 있는가? -> 일단 그런 것 같다. (틀렸습니다 발생)
        // 어차피 앞에 끝난 회의는 선택할 수 없을텐데?
        // 반례: 
        // 시작과 동시에 끝나는 회의가 있는 경우 -> 시작 느린 순으로 정렬하면, 시간축이 뒤로 이동해버린다.
        // 그래서 원래 가능했을 회의를 못하게 된다.

        /*
        ----- (a)
            . (b)
        이 경우 a,b 모두 가능하겠지만
            . (b)
        ----- (a)
        이 경우 b를 수행하면 a는 수행할 수 없다.

        고로 같은 시각에 끝나는 회의들 중에서 빨리 시작하는 회의들은 먼저 배치해야 한다.
        시간 축 t가 세로로 이동한다고 이미지화 시켜보자.
        시간축이 지나가면서, 시작시간을 지나쳐버린 회의는 다시 수행할 수 없다.
        회의를 하는데 비용이 드는것도 아니므로, 같이 끝나는 회의 중에선 시간축에 먼저 닿는 놈을 수행하는게 이득이다.
        |    . (b)
        |----  (a) <- 이런 경우, 둘 모두 가능하다.
        하지만 b먼저 평가하면 시간축이 이동하므로 a는 평가할 수 없다.
        */
        if (meetings[i].start >= time)
        {
            time = meetings[i].end;
            count++;
        }
    }
    cout << count;
}