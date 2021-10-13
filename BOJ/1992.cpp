// 2021.10.13 18:43:14
// 1992 https://boj.kr/1992
#include <bits/stdc++.h>
using namespace std;

string image[64];

class Point
{
public:
    int y, x;
};

class Range
{
public:
    Point leftTop, rightBottom;
    int size;

    Range getLeftTop()
    {
        return Range({Point({leftTop.y, leftTop.x}), Point({(leftTop.y + rightBottom.y) / 2, (leftTop.x + rightBottom.x) / 2}), size / 2});
    }
    Range getRightTop()
    {
        return Range({Point({leftTop.y, (leftTop.x + rightBottom.x) / 2}), Point({(leftTop.y + rightBottom.y) / 2, rightBottom.x}), size / 2});
    }
    Range getLeftBottom()
    {
        return Range({Point({(leftTop.y + rightBottom.y) / 2, leftTop.x}), Point({rightBottom.y, (leftTop.x + rightBottom.x) / 2}), size / 2});
    }
    Range getRightBottom()
    {
        return Range({Point({(leftTop.y + rightBottom.y) / 2, (leftTop.x + rightBottom.x) / 2}), Point({rightBottom.y, rightBottom.x}), size / 2});
    }
};

string compress(Range range)
{
    if (range.size == 1)
    {
        return image[range.leftTop.y].substr(range.leftTop.x, 1);
    }
    string ret = "(";
    string area[4] = {
        compress(range.getLeftTop()),
        compress(range.getRightTop()),
        compress(range.getLeftBottom()),
        compress(range.getRightBottom())};
    if (area[0][0] == area[1][0] &&
        area[1][0] == area[2][0] &&
        area[2][0] == area[3][0] &&
        (area[0][0] != '('))
        return area[0].substr(0, 1);
    for (auto &areaResult : area)
    {
        ret += areaResult;
    }
    ret += ")";
    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> image[i];
    }
    Range range = Range({Point({0, 0}), Point({n, n}), n});
    cout << compress(range);
}