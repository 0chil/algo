#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> qq;
int oy,ox, nn, mm;
const int dy[4] = {0,0,-1,1};
const int dx[4] = {-1,1,0,0};

bool inRange(int y, int x){
    return 0 <= y && y < nn && 0<= x && x<mm;
}

void adjustMoveRange(long long& y, long long& x){
    if(0 > y)
        y=0;
    else if(y >= nn)
        y = nn-1;
    if(0 > x)
        x=0;
    else if(x >= mm)
        x = mm-1;
    
}

long long query(int y, int x, int qidx){
    // if(qidx == qq.size()-1) {cout << y << ", " << x << endl ;}
    if(qidx == qq.size()-1){
        if(y == oy && x == ox) { return 1;}
        return 0;
    }
    
    int queryType = qq[qidx][0];
    int moveAmount = qq[qidx][1];
    
    long long nexty = y + dy[queryType]*moveAmount;
    long long nextx = x + dx[queryType]*moveAmount;
    
    // cout << y << ", " << x << "->" << nexty << ", " << nextx << endl ;
    adjustMoveRange(nexty,nextx);
    
    // cout << y << ", " << x << "->" << nexty << ", " << nextx << endl ;
    return query(nexty,nextx,qidx+1);
}

long long solution(int n, int m, int y, int x, vector<vector<int>> queries) {
    long long answer = 0;
    qq = queries;
    oy = y;
    ox = x;
    nn = n;
    mm = m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // cout << "start at " << i << ", " << j << endl ;
            answer += query(i,j,0);
            // cout << "===================" << endl ;
        }
    }
    
    return answer;
}