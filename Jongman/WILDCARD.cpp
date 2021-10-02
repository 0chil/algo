#include <bits/stdc++.h>
using namespace std;

string W, S;
int cache[101][101];
int f(int wPos, int sPos)
{
    int &ret = cache[wPos][sPos];
    if (ret != -1)
        return ret;
    if (wPos >= W.size() && sPos >= S.size())
        return 1;
    if (wPos > W.size() || sPos > S.size())
        return 0;
    if (W[wPos] == S[sPos] || W[wPos] == '?')
        return ret = f(wPos + 1, sPos + 1);
    if (W[wPos] == '*')
        if (f(wPos + 1, sPos) || f(wPos, sPos + 1))
            return ret = 1;
    return 0;
}

void clearCache()
{
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            cache[i][j] = -1;
}

int compare(string s1, string s2)
{
    return s1 < s2;
}

int main()
{
    int c;
    cin >> c;
        int i=0;
    while (c--)
    {
        cin >> W;
        int n;
        cin >> n;
        vector<string> files;
        while (n--)
        {
            clearCache();
            cin >> S;
            if (f(0, 0) == 1)
                files.push_back(S);
        }
        sort(files.begin(), files.end(), compare);
        for (int i = 0; i < files.size(); i++)
        {
            cout << files.at(i) << "\n";
        }
    }
}