// 2021.11.17 21:26:31
// 1167 https://boj.kr/1167
#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> edges(10001, vector<pair<int, int>>());

int maxLeaf = 0;
int maxLeafLength = 0;
void getFarthestLeaf(int currentNode, int previousNode, int length)
{
    if (edges[currentNode].size() == 1)
    {
        if (maxLeafLength < length)
        {
            maxLeaf = currentNode;
            maxLeafLength = length;
        }
    }

    for (auto &edge : edges[currentNode])
    {
        if (edge.first == previousNode)
            continue;
        getFarthestLeaf(edge.first, currentNode, length + edge.second);
    }
}

int getLength(int currentNode, int previousNode)
{
    int ret = 0;
    for (auto &edge : edges[currentNode])
    {
        if (edge.first == previousNode)
            continue;
        ret = max(ret, getLength(edge.first, currentNode) + edge.second);
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int v;
    cin >> v;

    for (int i = 0; i < v-1; i++)
    {
        int e1, e2, length;
        cin >> e1 >> e2 >> length;
        edges[e1].push_back(make_pair(e2, length));
        edges[e2].push_back(make_pair(e1, length));
    }

    getFarthestLeaf(1, 0, 0);
    cout << getLength(maxLeaf, 0);
}