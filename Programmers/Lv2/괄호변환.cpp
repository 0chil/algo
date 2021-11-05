#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool isVps(string& s){
    stack<char> charStack;
    for(int i=0;i<s.length();i++){
        char& c = s[i];
        if(c == ')'){
            if(charStack.empty()){
                return false;
            }else{
                charStack.pop();
            }
            
        }
        else{
            charStack.push(c);
        }
    }
    return true;
}

string getBs(string& p){
    int opened = 0;
    string u;
    for(int i=0;i<p.length();i++){
        char& c = p[i];
        if(c == '('){
            opened++;
            u.push_back(c);
        }
        else{
            opened--;
            u.push_back(c);
        }
        if(opened==0) break;
    }
    return u;
}

string cutAndReverse(string& s){
    string ret = s.substr(1, s.length()-2);
    for(auto& c : ret){
        c = (c=='('?')':'(');
    }
    return ret;
}

string solution(string p) {
    string answer;
    if(p.empty()){
        answer="";
    }
    else if(isVps(p)){
        answer = p;
    }
    else{
        string u, v;
        //u, v 뱉기.
        u = getBs(p);
        v = p.substr(u.size(),p.size()-u.size());
        if(isVps(u)){
            answer = u;
            answer += solution(v);
            
        }
        else{
            answer += '(';
            answer += solution(v);
            answer += ')';
            answer += cutAndReverse(u);
        }
    }
    return answer;
}