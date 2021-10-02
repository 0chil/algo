// 2021.09.08 22:05:29
// 1406 http://boj.kr/1406
#include <bits/stdc++.h>
using namespace std;

class Editor
{
public:
    list<char> content;
    list<char>::iterator cursor;

    Editor(){
        cursor = content.end();
    }

    void push_character(const char &c){
        content.push_back(c);
    }

    void go_left(){
        if(cursor == content.begin()) return;
        --cursor;
    }

    void go_right(){
        if(cursor == content.end()) return;
        ++cursor;
    }

    void delete_left(){
        if(cursor == content.begin()) return;
        list<char>::iterator del_it(cursor);
        del_it--;
        cursor = content.erase(del_it);
    }

    void push_left(char &c){
        list<char>::iterator it2(cursor);
        content.insert(it2,c);
    }

    void print(){
        list<char>::iterator it2=content.begin();
        while(it2!=content.end()){
            cout << *it2;
            it2++;
        }
    }
};
int main()
{
    char c;
    Editor e;
    while((c=getchar())!='\n'){
        e.push_character(c);
    }
    int M;
    cin >> M;
    while(M--){
        string command;
        cin >> command;
        if(command[0] == 'L')
            e.go_left();
        else if(command[0]=='D')
            e.go_right();
        else if(command[0]=='B')
            e.delete_left();
        else if(command[0]=='P'){
            char x;
            cin >> x;
            e.push_left(x);
        }
    }
    e.print();
}