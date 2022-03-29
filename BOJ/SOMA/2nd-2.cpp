// 2022.03.19 20:33:54
// 2nd-2
#include <bits/stdc++.h>
using namespace std;

int parent[1'000'001];
int score[1'000'001];
int people[1'000'001];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void join(int a, int b)
{
    a = find(a);
    b = find(b);
    if (score[b] && !score[a])
    {
        swap(a, b);
        cout << "swap";
    }
    parent[b] = a;
    if (score[b] > 0)
    {
        score[a] += score[b];
        people[a] += people[b];
    }
}

bool isUnion(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return true;
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int scoreAccum = 0;
    for (int i = 0; i < m; i++)
    {
        int m, s;
        cin >> m >> s;
        score[m] = s;
        people[m] = 1;
        scoreAccum += s;
    }

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        join(a, b);
    }

    for (int i = 1; i <= n; i++)
    {
        int root = find(i);
        if (score[i] == 0)
            scoreAccum += score[root] / people[root];
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     if (score[i] == 0)
    //         scoreAccum += visited[find(i)];
    // }
    string answer = to_string((double)scoreAccum / n);
    answer = answer.substr(0, answer.find('.') + 3);
    cout << answer;
}

// 5 3 3 1 4 2 5 4 3 1 2 3 2 5 4