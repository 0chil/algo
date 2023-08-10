// 2023.08.10 17:49:08
// 2217 https://boj.kr/2217
#include <bits/stdc++.h>
using namespace std;

bool sorter(int i, int j)
{
    return (i > j);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;

    int tolerances[100'001];
    for (int i = 0; i < n; i++)
    {
        cin >> tolerances[i];
    }

    sort(tolerances, tolerances + n, sorter);

    int maxTolerance = INT_MIN;
    // 인내력이 큰 로프들만 k개 선택해보고,
    // 그 중 제일 작은 놈을 기준으로 기존보다 크면 사용한다.

    /*
        ------
        -----
        ----
        -
        이런 경우라고 가정하자.
        인내력 큰 순으로 선택하는건 직관적이므로 이유를 생략한다.
        선택한 놈들 중 가장 인내력 작은 놈을 기준으로 버티는 한계를 계산해야 한다.
        가장 중량 작은 놈이 버티는 한계가 들수 있는 최대이며,
        인내력을 나눠줄 순 없기 때문이다.
        (2차원 면적으로 생각하면 쉽다)
    */
    for (int k = 1; k <= n; k++)
    {
        maxTolerance = max(maxTolerance, tolerances[k - 1] * k);
    }
    cout << maxTolerance;
}