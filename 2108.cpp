// 2022.02.25 23:29:11
// 2108 https://boj.kr/2108
#include <bits/stdc++.h>
using namespace std;

int numbers[500001];
int freq[10000];
int n;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        numbers[i] = num;
        total += num;
        freq[num + 4000]++;
    }

    sort(numbers, numbers + n);

    int mostFreq = 0;
    int prevMostFreq = 0;

    for (int i = n-1; i >=0; i--)
    {
        int num = numbers[i];
        int frequency = freq[num + 4000];
        int prevFrequency = freq[mostFreq + 4000];
        i -= frequency - 1;
        if (frequency == prevFrequency)
        {
            prevMostFreq = mostFreq;
            mostFreq = num;
        }

        if (frequency > prevFrequency)
        {
            prevMostFreq = 0;
            mostFreq = num;
        }
    }
    
    cout << (int)round((double)total / n) << '\n';
    cout << numbers[n / 2] << '\n';
    if (freq[mostFreq+4000]== freq[prevMostFreq+4000])
        cout << prevMostFreq << '\n';
    else
        cout << mostFreq << '\n';
    cout << (numbers[n - 1] - numbers[0]);
}