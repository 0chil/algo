// 2021.09.12 16:35:22
// 10820 https://boj.kr/10820
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    char c;
    int info[4] = {0};
    while ((c = getchar()))
    {
        if ('a' <= c && c <= 'z')
        {
            info[0]++;
        }
        else if ('A' <= c && c <= 'Z')
        {
            info[1]++;
        }
        else if ('0' <= c && c <= '9')
        {
            info[2]++;
        }
        else if (c == ' ')
        {
            info[3]++;
        }
        else if (c == '\n' || c == EOF)
        {
        	if(info[0]+info[1]+info[2]+info[3]!=0)
            	cout << info[0] << ' ' << info[1] << ' ' << info[2] << ' ' << info[3] << '\n';
            info[0]=info[1]=info[2]=info[3]=0;
            if(c==EOF) return 0;
        }
    }
}