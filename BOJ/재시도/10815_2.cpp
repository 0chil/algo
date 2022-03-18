// 2022.03.18 17:51:39
// 10815_2 https://boj.kr/10815_2
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    set<int> s;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        cout << (s.find(temp) != s.end()) << ' ';
    }
}