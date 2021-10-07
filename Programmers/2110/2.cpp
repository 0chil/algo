#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    long long index=left;
    int i= left/n, j=left%n;
    for(;i<n;i++){
        for(;j<n;j++,index++){
            if(left <= index && index <= right){
                answer.push_back(max(i,j)+1);
            }
            if(index > right) 
            {i=n;break;}
        }
        j=0;
    }
    
    
    
    
    return answer;
}