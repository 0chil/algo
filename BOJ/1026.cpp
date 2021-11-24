// 2021.11.25 00:28:21
// 1026 https://boj.kr/1026
#include <bits/stdc++.h>
using namespace std;

vector<int > a;
priority_queue<int> pq;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, input;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        a.push_back(input);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        pq.push(input);
    }

    sort(a.begin(), a.end());

    int answer = 0;
    int it = 0;
    while(!pq.empty()){
        answer += pq.top() * a[it++];
        pq.pop();
    }

    cout << answer;
}