// 2021.11.13 09:21:16
// 1991 https://boj.kr/1991
#include <bits/stdc++.h>
using namespace std;
map<char, pair<char, char>> nodes;
int n;

void preorder(char node){
    cout << node;
    char left =nodes[node].first, right = nodes[node].second;
    if(left != '.'){
        preorder(left);
    }
    if(right != '.'){
        preorder(right);
    }
}

void inorder(char node){
    char left =nodes[node].first, right = nodes[node].second;
    if(left != '.'){
        inorder(left);
    }
    cout << node;
    if(right != '.'){
        inorder(right);
    }
}

void postorder(char node){
    char left =nodes[node].first, right = nodes[node].second;
    if(left != '.'){
        postorder(left);
    }
    if(right != '.'){
        postorder(right);
    }
    cout << node;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char root, left, right;
        cin >> root >> left >> right;
        nodes[root] = make_pair(left, right);
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
}