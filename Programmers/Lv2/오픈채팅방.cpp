#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


unordered_map<string, string> user;
class EnterLog{
public:
    string uid;
    int action;
    
    string getLogWithNickname(){
        string result;
        result += user[this->uid];
        if(this->action == 0){
            result+="님이 들어왔습니다.";
        }else{
            result+="님이 나갔습니다.";
        }
        return result;
    }
};

vector<EnterLog> enterLog;

vector<string> split(string str, char diameter){
    vector<string> ret = {""};
    for(int i=0;i<str.size();i++){
        if(str[i] == diameter){
            string newstr;
            ret.push_back(newstr);
        }
        else{
            ret[ret.size()-1].push_back(str[i]);
        }
    }
    return ret;
}

vector<string> solution(vector<string> record) {
    for(auto& rec : record){
        vector<string> infos = split(rec,' ');
        if(rec[0] == 'E'){
            enterLog.push_back(EnterLog({infos[1],0}));
            user[infos[1]] = infos[2];
        }
        else if(rec[0] == 'L'){
            enterLog.push_back(EnterLog({infos[1],1}));
        }
        else{
            user[infos[1]] = infos[2];
        }
    }
    vector<string> answer;
    for(auto& log : enterLog){
        answer.push_back(log.getLogWithNickname());
    }
    return answer;
}