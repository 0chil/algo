// 2021.11.23 19:55:57
// 2562 https://boj.kr/2562
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int largestNum=0, largestNumIdx=0, input;
    for(int i=1;i<=9;i++){
        cin >> input;
        if(largestNum < input){
            largestNum = input;
            largestNumIdx = i;
        }
    }

    cout << largestNum << '\n' << largestNumIdx;
}