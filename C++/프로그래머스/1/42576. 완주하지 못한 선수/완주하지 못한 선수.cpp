#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> player;  // 문자열 -> 숫자 자료구조 만들어 놓고
    
    for(int i=0;i<participant.size();i++){   // 참가 선수 전부 때려 넣기
        player[participant[i]]++;
    }
    
    for(int i=0;i<completion.size();i++){     // 완주한 선수는 -1
        player[completion[i]]--;
    }
    
    for(auto p: player){    // 전체 순회하면서
        if(p.second==1){    // 숫자가 1인 애만 찾아서
            return p.first; // 이름을 반환
        }
    }
}