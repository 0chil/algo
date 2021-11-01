#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer;

void printarr(vector<char> &arr)
{
    for (auto &i : arr)
    {
        cout << i << " ";
    }
    cout << '\n';
}

void permutation(vector<char> &arr, int start, int &n, vector<string> &data)
{
    if (start == 8)
    {
        bool pass = true;
        for (int i = 0; i < n; i++)
        {
            char a = data[i][0], b = data[i][2];
            char compute = data[i][3];
            int dist = data[i][4] - '0';

            int apos;
            for (apos = 0; apos < 8; apos++)
            {
                if (arr[apos] == a)
                    break;
            }
            int bpos;
            for (bpos = 0; bpos < 8; bpos++)
            {
                if (arr[bpos] == b)
                {
                    break;
                }
            }
            // cout << apos << ", " << bpos << '\n';
            int distance = abs(apos - bpos) - 1;
            if (compute == '=')
            {
                if (dist != distance)
                {
                    pass = false;
                    break;
                }
            }
            else if (compute == '<')
            {
                if (dist <= distance)
                {
                    pass = false;
                    break;
                }
            }
            else if (compute == '>')
            {
                if (dist >= distance)
                {
                    pass = false;
                    break;
                }
            }
        }
        if (pass)
            answer++;
    }
    for (int i = start; i < 8; i++)
    {
        swap(arr[start], arr[i]);
        permutation(arr, start + 1, n, data);
        swap(arr[start], arr[i]);
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
    answer = 0;
    vector<char> arr = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
    permutation(arr, 0, n, data);

    return answer;
}