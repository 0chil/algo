#include <iostream>
#include <cstring>

using namespace std;

bool rel[10][10];
int n,m;

int f(bool people[10]){
    int notRel = -1;
    for(int i=0;i<n;i++){
        if(!people[i]){
            notRel = i;
            break;
        }
    }
    if(notRel == -1) return 1;
    int sum = 0;
    for(int i=notRel+1;i<n;i++){
        if(!people[i] && rel[notRel][i]){
            people[notRel] = people[i] = true;
            sum += f(people);
            people[notRel] = people[i] = false;
        }
    }
    return sum;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        for(int i=0;i<10;i++)
            memset(rel[i],0,sizeof(bool)*10);
        cin >> n >> m;
        for(int i=0;i<m;i++){
            int x,y;
            cin >> x >> y;
            rel[x][y] = rel[y][x] = true;
        }
        bool people[10]={0,0,0,0,0,0,0,0,0,0};
        cout << f(people) << '\n';
    }
}