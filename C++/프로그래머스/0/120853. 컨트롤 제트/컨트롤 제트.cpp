#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int last = 0;
    
    istringstream iss(s);
    string word;
    while(iss >> word){
        if(word=="Z"){
            answer -= last;
            continue;
        }
        last = stoi(word);
        answer += last;
    }
    
    return answer;
}