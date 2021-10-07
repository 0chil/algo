#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> grid;

bool visited[501][501] = {};
bool recur[501][501] = {};

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int maxY,maxX;

class Node
{
public:
    int y, x;
    int y_prev, x_prev;
};

int boundY(int& y){
    if(y<0) return maxY;
    if(y>maxY) return 0;
    return y;
}

int boundX(int& x){
    if(x<0) return maxX;
    if(x>maxX) return 0;
    return x;
}

bool dfs(Node v)
{
    visited[v.y][v.x] = true;
    recur[v.y][v.x] = true;

    Node b;
    b.y_prev = v.y;
    b.x_prev = v.x;
    //get next node by char
    if (grid[v.y][v.x] == 'S')
    {
        //다음꺼 = 현재점 + (현재 - 기존거)
        b.y = v.y + (v.y - v.y_prev);
        b.x = v.x + (v.x - v.x_prev);
    }
    else if (grid[v.y][v.x] == 'L')
    {
        //다음꺼 = 현재점 + (현재 - 기존거),y<->x, 부호 반대
        b.y = v.y - (v.x - v.x_prev);
        b.x = v.x - (v.y - v.y_prev);
    }
    else if (grid[v.y][v.x] == 'R')
    {
        //다음꺼 = 현재점 + (현재 - 기존거), 부호 반대
        b.y = v.y - (v.y - v.y_prev);
        b.x = v.x - (v.x - v.x_prev);
    }

    if (!visited[b.y][b.x] && dfs(b))
    {
        return true;
    }
    else if (recur[b.y][b.x])
    {
        return true;
    }

    recur[v.y][v.x] = false;
    return false;
}

/* boolean dfs(v, visited,recur){
    visited[v] = true;
    recur[v] = true;
    
    for(v 와 연결된 점 수){
        b = 한 정점
        if(!visited[b] && dfs(b,visited,recur)){
            return true;
        }
        else if(recur[b]){
            return true;
        }
        
        recur[a]=false;
        return false;
    }
} */

int main()
{
    //EX1
    grid.push_back("SL");
    grid.push_back("LR");

    vector<bool> answer;
    Node n;
    n.y = 0;
    n.x = 0;
    for (int i = 0; i < 4; i++)
    {
        n.y_prev = dy[i];
        n.x_prev = dx[i];
        int ret = dfs(n);
        if (ret)
            answer.push_back(ret);
    }

    sort(answer.begin(), answer.end());

    for (auto b : answer)
    {
        cout << b << ", ";
    }
    return 0;
}