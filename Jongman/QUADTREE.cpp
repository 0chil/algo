#include <iostream>
#include <string>
using namespace std;


string s;

string f(int& loc){
    char c = s[loc++];
    if(c!='x') return string(1,c);
    string quad[4];
    for(int i=0;i<4;i++){
        quad[i] = f(loc);
    }
    return string("x")+quad[2]+quad[3]+quad[0]+quad[1];
}


int main(){
    int c;
    cin >> c;
    while(c--){
        cin >> s;
        int i=0;
        cout << f(i) << '\n';
    }
}