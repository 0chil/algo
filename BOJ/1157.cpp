// 2021.11.30 18:19:02
// 1157 https://boj.kr/1157
#include <bits/stdc++.h>
using namespace std;

int occurrences['z' - 'a'];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int maxOccurrence = 0;
    char maxOccurrenceAlphabet = 0;
    int maxOccurrenceCnt = 0;

    char c;
    while (cin >> c)
    {
        if (c < 'a')
            c += 'a' - 'A';
        occurrences[c - 'a'] += 1;
        if (occurrences[c - 'a'] > maxOccurrence)
        {
            maxOccurrence = occurrences[c - 'a'];
            maxOccurrenceAlphabet = c;
            maxOccurrenceCnt = 1;
        }
        else if (occurrences[c - 'a'] == maxOccurrence)
        {
            maxOccurrenceCnt++;
        }
    }

    if (maxOccurrenceCnt > 1)
        cout << "?";
    else
    {
        maxOccurrenceAlphabet -= 'a' - 'A';
        cout << maxOccurrenceAlphabet;
    }
}