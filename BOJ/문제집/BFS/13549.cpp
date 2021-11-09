// 2021.11.08 20:19:31
// 13549 https://boj.kr/13549
#include <bits/stdc++.h>
using namespace std;
int n, k;
int visited[200001];
class Node
{
public:
    int pos, time;

    bool isVisited()
    {
        return visited[pos];
    }

    bool isInRange()
    {
        return 0 <= pos && pos < 200001;
    }

    void visit()
    {
        visited[pos] = 1;
    }
};

int bfs(Node start)
{
    queue<Node> q;
    q.push(start);
    start.visit();

    while (!q.empty())
    {
        Node cur = q.front();
        q.pop();

        if(cur.pos > k){
            cur = {cur.pos-1,cur.time+1};
            q.push(cur);
            continue;
        }
        if (cur.pos == k)
        {
            return cur.time;
        }

        Node next[3] = {
            {cur.pos*2, cur.time}, // 시간 안들이는 놈을 먼저 접근(같은 depth에 있는 노드 추가)
            {cur.pos -1 , cur.time+1},
            {cur.pos+1, cur.time+1},
        };

        for(int i=0; i<3;i++){
            if(next[i].isInRange() && !next[i].isVisited()){
                q.push(next[i]);
                next[i].visit();
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;

    Node start = {n, 0};

    cout << bfs(start);
}