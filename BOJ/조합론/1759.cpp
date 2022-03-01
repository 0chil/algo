// 2022.02.28 20:30:06
// 1759 https://boj.kr/1759
#include <bits/stdc++.h>
using namespace std;
const char vowelCandidate[] = {'a', 'e', 'i', 'o', 'u'};

vector<char> chars;
int l, c;

void brute(int ci, int vowelCnt, string &sofar)
{
    // cout << "(" << ci << ", " << vowelUsed << ", " << sofar << ")\n";
    if (sofar.size() == l && vowelCnt > 0 && l - vowelCnt >= 2)
    {
        cout << sofar << '\n';
        return;
    }
    if (ci >= chars.size())
        return;

    if (sofar.length() == 0 || sofar[sofar.length() - 1] < chars[ci])
    {
        char cur = chars[ci];
        bool isVowel = false;
        for (char comp : vowelCandidate)
            if (cur == comp)
            {
                isVowel = true;
                break;
            }

        sofar.push_back(cur);
        brute(ci + 1, isVowel ? vowelCnt + 1 : vowelCnt, sofar);
        sofar.pop_back();
        brute(ci + 1, vowelCnt, sofar);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> l >> c;

    for (int i = 0; i < c; i++)
    {
        char temp;
        cin >> temp;
        chars.push_back(temp);
    }
    sort(chars.begin(), chars.end());
    string s;
    brute(0, 0, s);
}