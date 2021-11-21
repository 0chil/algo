// 2021.11.21 20:02:25
// 7662 https://boj.kr/7662
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        multiset<int> s;
        int k;
        cin >> k;
        while (k--)
        {
            char instruction; int number;
            cin >> instruction >> number;

            if(instruction == 'I'){
                s.insert(number);
            }
            else if(instruction == 'D'){
                if(s.size() == 0) continue;
                if(number == -1){
                    s.erase(s.begin());
                }
                else{
                    s.erase(--s.end());
                }
            }
        }
        if(s.size() > 0){
            cout << *(--s.end()) << ' ' << *(s.begin()) << endl;
        }
        else{
            cout << "EMPTY" << endl;
        }
    }
}