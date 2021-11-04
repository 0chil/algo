#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}

long long solution(int w,int h) {
    long long answer = 1;
    
    long long div = gcd(w,h);
    answer = (long long)w*h-(w+h-div);
    return answer;
}