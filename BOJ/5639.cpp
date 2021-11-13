// 2021.11.13 09:39:05
// 5639 https://boj.kr/5639
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int num;

    Node *left, *right;
};

void traverse(Node *node)
{
    if (node->left)
        traverse(node->left);
    if (node->right)
        traverse(node->right);
    cout << node->num << '\n';
}

Node *insert(Node *root, int num)
{
    if (!root)
    {
        root = new Node({num});
    }
    else if (root->num > num)
    {
        root->left = insert(root->left, num);
    }
    else
    {
        root->right = insert(root->right, num);
    }
    return root;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int tmp;
    cin >> tmp;
    Node *root = new Node({tmp});
    while (cin >> tmp)
    {
        insert(root, tmp);
    }
    traverse(root);
}