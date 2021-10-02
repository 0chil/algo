#include <bits/stdc++.h>
#define CLOCK_CNT 16
using namespace std;
vector<vector<int>> link = vector<vector<int>>({
    vector<int>({0,1,2}),
    vector<int>({3,7,9,11}),
    vector<int>({4, 10, 14, 15}),
    vector<int>({0, 4, 5, 6, 7}),
    vector<int>({6, 7, 8, 10, 12}),
    vector<int>({0, 2, 14, 15}),
    vector<int>({3, 14, 15}),
    vector<int>({4, 5, 7, 14, 15}),
    vector<int>({1, 2, 3, 4, 5}),
    vector<int>({3, 4, 5, 9, 13})
});

vector<int> clocks(CLOCK_CNT);

bool isAligned(){
    for(int i=0;i<CLOCK_CNT;i++)
        if(clocks[i] != 12) return false;
    return true;
}

void push(vector<int>& clocks, int sw){
    for(int i=0;i<link[sw].size();i++){
        clocks[link[sw][i]] += 3;
        if(clocks[link[sw][i]]==15) clocks[link[sw][i]]=3;
    }
}

int f(vector<int>& clocks, int sw){
    if(sw==10) return isAligned()?0:9999;
    int sum=9999;
    for(int p=0;p<4;p++){
        sum = min(sum,p+f(clocks,sw+1));
        push(clocks,sw);
    }
    return sum;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        for(int i=0;i<CLOCK_CNT;i++)
            cin >> clocks[i];
        int ans = f(clocks,0);
        if(ans == 9999) ans = -1;
        cout << ans << '\n';
    }
}