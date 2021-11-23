// 2021.11.23 19:50:45
// 3052 https://boj.kr/3052
#include <bits/stdc++.h>
using namespace std;

int counter[42];
int diffCount = 0;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int num;
    for(int i=0; i<10; i++){
        cin >> num;
        auto& cnt = counter[num%42];
        if(cnt == 0){
            cnt = 1;
            diffCount++;
        }
    }

    cout << diffCount;
}