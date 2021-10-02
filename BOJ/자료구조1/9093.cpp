// 2021.09.08 18:50:07
// 9093 http://boj.kr/9093
#include <bits/stdc++.h>
using namespace std;

void print_reverse(string &s,int from,int to){
    for(int p=to;p>=from;p--){
        cout << s[p];
    }
}
int main(){
    int n;
    cin >>n;
    cin.ignore();
    while(n--){
        string s;
        getline(cin,s);
        int from =0;
        for(int i=0;i<s.size();i++){
            if(s[i] == ' '){
                print_reverse(s,from,i-1);
                cout << ' ';
                from =i+1;
                continue;
            }
            else if(i==s.size()-1){
                print_reverse(s,from,i);
            }
        }
        cout << '\n';
    }
}