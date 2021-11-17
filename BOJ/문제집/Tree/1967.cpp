// 2021.11.17 17:29:07
// 1967 https://boj.kr/1967
#include <bits/stdc++.h>
using namespace std;

vector<int> leaves;
vector<vector<pair<int, int>>> edges;

void getLeaves(int currentNode, int previousNode)
{
    if (edges[currentNode].size() == 1)
    {
        leaves.push_back(currentNode);
    }

    for (auto &edge : edges[currentNode])
    {
        if (edge.first == previousNode)
            continue;
        getLeaves(edge.first, currentNode);
    }
}

int getLength(int currentNode, int previousNode)
{
    int length = 0;
    for(auto& edge : edges[currentNode]){
        if(edge.first == previousNode) continue;
        length = max(length, getLength(edge.first, currentNode) + edge.second);
    }
    return length;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    edges = vector<vector<pair<int, int>>>(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < n - 1; i++)
    {
        int e1, e2, length;
        cin >> e1 >> e2 >> length;
        edges[e1].push_back(make_pair(e2, length));
        edges[e2].push_back(make_pair(e1, length));
    }

    getLeaves(1, 0);

    int maxLength = 0;
    for (auto &leaf1 : leaves)
    {
        maxLength = max(maxLength, getLength(leaf1,0));
    }
    
    cout << maxLength;
}