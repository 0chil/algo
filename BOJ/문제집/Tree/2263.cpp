// 2021.11.30 13:28:39
// 2263 https://boj.kr/2263
#include <bits/stdc++.h>
using namespace std;
vector<int> inorder(100001, 0), postorder(100001, 0), idx(100001, 0);
int n;
class Range
{
public:
    int startInclusive, endExclusive;

    int size()
    {
        return endExclusive - startInclusive;
    }
};

void printPreorder(Range inRange, Range postRange)
{
    if (inRange.startInclusive >= inRange.endExclusive)
        return;
    if (postRange.startInclusive >= postRange.endExclusive)
        return;
    int root = postorder[postRange.endExclusive - 1];
    int rootIndexInInorder = idx[root];
    int leftSize = rootIndexInInorder - inRange.startInclusive;
    cout << root << ' ';
    printPreorder({inRange.startInclusive, rootIndexInInorder}, {postRange.startInclusive, postRange.startInclusive + leftSize});
    printPreorder({rootIndexInInorder + 1, inRange.endExclusive}, {postRange.startInclusive + leftSize, postRange.endExclusive - 1});
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }

    printPreorder({0, n}, {0, n});
}