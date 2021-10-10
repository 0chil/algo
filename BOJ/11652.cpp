// 2021.10.09 23:42:18
// 11652 https://boj.kr/11652
#include <bits/stdc++.h>
using namespace std;

/*

맵에 숫자 등록.
맵[숫자] 가 없으면 stack에 넣고 계속
맵[숫자] ++;

스택에서 숫자꺼내고
맵[숫자] 개수 확인



*/

map<long long, int> oc;

int main()
{

    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    long long input;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> input;
        oc[input]++;
    }

    int maxOc = 0;
    map<long long, int>::iterator it = oc.begin();
    long long answer = LONG_LONG_MAX;
    while (it != oc.end())
    {
        if (maxOc < it->second)
        {
            answer = it->first;
            maxOc = it->second;
        }
        else if(maxOc == it->second){
            answer = min(answer, it->first);
        }
        it++;
    }

    cout << answer;
}