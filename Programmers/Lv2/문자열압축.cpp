#include <string>
#include <vector>
#include <iostream>

using namespace std;

int compress(const string& s, int by){
    string compar,result;
    int eqCnt=1;
    compar = s.substr(0,by);
    for(int i=by;i<s.size();i+=by){
        if(compar == s.substr(i,by)){
            eqCnt++;
        }
        else{
            result+= compar;
            if(eqCnt>1) result+=to_string(eqCnt);
            eqCnt=1;
            compar = s.substr(i,by);
        }
    }
    result+= compar;
    if(eqCnt>1) result+=to_string(eqCnt);
    return result.size();
}

int solution(string s) {
    int answer = s.size();
    for(int i=1;i<s.size();i++){
        answer = min(answer,compress(s, i));
    }
    return answer;
}