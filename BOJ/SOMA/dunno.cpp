// 2022.03.11 12:32:18
// dunno https://boj.kr/dunno
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 암호화 된 문자열과 키(a, b)를 줌
 *
 * 암호화 방식은 모듈로 연산에 의함
 * (a * 원문 + b) mod 26 = 암호화된 문자
 *
 * @return 복호화된 문자열
 *
 * TC
 * 3 4
 * g u o e
 * s o m a
 */

int a, b;

char decrypt(char enc)
{
    enc = enc - 'a';
    char ret = 0;
    for (; ret < 26; ret++)
    {
        int calc = (a * ret + b) % 26;
        if (calc == enc)
            break;
    }
    return ret + 'a';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> a >> b;
    string enc, dec;
    cin >> enc;

    for (char e : enc)
    {
        dec.push_back(decrypt(e));
    }
    cout << dec;
}