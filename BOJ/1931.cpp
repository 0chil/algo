// 2021.11.11 19:46:00
// 1391 https://boj.kr/1391
#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>& a, pair<int,int>& b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    vector<pair<int, int> > meetings;
    for(int i=0;i<n;i++){
        int start, end;
        cin>> start >> end;
        meetings.push_back(make_pair(start,end));
    }

    sort(meetings.begin(), meetings.end(),compare);

    int start = 0;
    int total = 0;
    for(auto& meeting : meetings){
        if(meeting.first >= start){
            start = meeting.second;
            total++;
        }
    }

    cout << total;
}