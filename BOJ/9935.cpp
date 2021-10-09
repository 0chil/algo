// 2021.10.09 22:08:23
// 9935 https://boj.kr/9935
#include <bits/stdc++.h>
using namespace std;
string s, bomb;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s >> bomb;
    string result;
    for (int i = 0; i < s.size(); i++)
    {
        result.push_back(s[i]);
        if (s[i] == bomb[bomb.length() - 1])
        {
            bool isBomb=true;
            for (int bombIndex = bomb.length() - 1; bombIndex >= 0; bombIndex--)
            {
                if(result[result.length() -bomb.length()+bombIndex] != bomb[bombIndex]){
                    isBomb=false;
                    break;
                }
            }
            if(isBomb){
                for(int j=0;j<bomb.length();j++){
                    result.pop_back();
                }
            }
        }
    }
    if (result.length() == 0)
        result = "FRULA";
    cout << result;
}
