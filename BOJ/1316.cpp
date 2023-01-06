// 2023.01.06 20:01:23
// 1316 https://boj.kr/1316
#include <bits/stdc++.h>
using namespace std;

class Word
{
public:
    string word;
    bool visited[101];
    bool found[27];

    bool isValid(int index)
    {
        return 0 <= index && index < word.length();
    }

    int alphabetOrderOf(char a)
    {
        return a - 'a';
    }

    bool isGroupWord()
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (!visited[i])
            {
                int alphabeticOrder = alphabetOrderOf(visit(i));
                if (found[alphabeticOrder])
                {
                    return false;
                }
                found[alphabeticOrder] = true;
            }
        }
        return true;
    }

    char visit(int i)
    {
        visited[i] = true;
        if (isValid(i + 1) && word[i + 1] == word[i])
        {
            return visit(i + 1);
        }
        return word[i];
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        if (Word({input}).isGroupWord())
        {
            count++;
        }
    }
    cout << count;
}