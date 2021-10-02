#include <iostream>
#include <vector>
using namespace std;
int H,W;
vector<vector<int>> board(20,vector<int>(20, 0));
const int dx[4][2] = {{1,0},{1,1},{1,0},{-1,0}};
const int dy[4][2] = {{0,1},{0,1},{1,1},{1,1}};

bool inRange(int y,int x){
    if(y>=0 && x>=0 && y<H && x<W) return true;
    return false;
}

int f(vector<vector<int>>& board){
    int emptyX=-1,emptyY=-1;
    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            if(!board[y][x]){
                emptyY = y;
                emptyX = x;
                break;
            }
        }
        if(emptyY != -1) break;
    }
    if(emptyY == -1) {
        return 1;
    }
    int sum =0;
        for(int i=0;i<4;i++){
            if(
                inRange(emptyY+dy[i][0],emptyX+dx[i][0]) &&
                inRange(emptyY+dy[i][1],emptyX+dx[i][1]) &&
                !board[emptyY+dy[i][0]][emptyX+dx[i][0]] &&
                !board[emptyY+dy[i][1]][emptyX+dx[i][1]]
            ){
                board[emptyY][emptyX] = board[emptyY+dy[i][0]][emptyX+dx[i][0]] = board[emptyY+dy[i][1]][emptyX+dx[i][1]] = true;
                sum += f(board);
                board[emptyY][emptyX] = board[emptyY+dy[i][0]][emptyX+dx[i][0]] = board[emptyY+dy[i][1]][emptyX+dx[i][1]] = false;
            }
        }
    return sum;
}

int main(){
    int c;
    cin >> c;
    while(c--){
        cin >> H >> W;
        board = vector<vector<int>>(20,vector<int>(20, 0));
        for(int y=0;y<H;y++){
            for(int x=0;x<W;x++){
                char temp;
                cin >> temp;
                board[y][x] = temp-'.'?1:0; // '.' 이면 false, '#' 이면 true
            }
        }
        cout << f(board) << '\n';
    }
}