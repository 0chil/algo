// 2021.11.30 14:44:16
// 2250 https://boj.kr/2250
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> nodeMin(10001,10000);
vector<int> nodeMax(10001,0);

class Node
{
public:
    Node *left;
    Node *right;
    Node *parent;
    bool visited = false;
};
int trav = 1;
void dfs(Node *root, int depth){
    if(root == nullptr) return;
    dfs(root->left,depth+1);
    nodeMax[depth] = max(nodeMax[depth],trav);
    nodeMin[depth] = min(nodeMin[depth],trav);
    trav++;
    dfs(root->right,depth+1);
}

Node* findRoot(Node* node){
    if(node == nullptr || node->visited) return nullptr;
    if(node->parent == nullptr) return node;
    node->visited = true;
    Node* ret = nullptr;
    ret = max(ret,findRoot(node->left));
    ret = max(ret,findRoot(node->right));
    ret = max(ret,findRoot(node->parent));
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    int num, left, right;
    vector<Node> v(10001, Node());
    for (int i = 1; i <= n; i++)
    {
        cin >> num >> left >> right;
        if (left != -1)
        {
            v[num].left = &v[left];
            v[num].left->parent = &v[num];
        }
        if (right != -1)
        {
            v[num].right = &v[right];
            v[num].right->parent = &v[num];
        }
    }

    Node* root = findRoot(&v[1]);
    dfs(root,1);

    int i=1, maxBreadth = 0, maxBreadthDepth = 0;
    while(nodeMax[i] != 0){
        int breadth = nodeMax[i] - nodeMin[i] + 1;
        if(maxBreadth < breadth){
            maxBreadth = breadth;
            maxBreadthDepth = i;
        }
        i++;
    }

    cout << maxBreadthDepth << " " << maxBreadth;
}