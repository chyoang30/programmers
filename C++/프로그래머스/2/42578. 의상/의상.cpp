#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


int solution(vector<vector<string>> clothes) {
    /* [A, 모자], [B, 모자], [C, 셔츠], [D, 셔츠], [E, 신발] -> 이런 식으로 있다고 해보면
    
    1개 고르는 경우: 5가지 (각각 하나씩 입는 경우)
    2개 고르는 경우: 8가지 (모자, 셔츠), (모자, 신발), (셔츠, 신발)
    3개 고르는 경우: 4가지 (모자, 셔츠, 신발)
    -> 답은 17
    
    모자를 선택하는 방법: A, B, 안 고름
    셔츠를 선택하는 방법: C, D, 안 고름
    신발을 선택하는 방법: E, 안 고름
    
    3*3*2-1=17 (-1은 왜? -> 안 고름만 3개인 경우를 뺌)
    */
    
    unordered_map<string, int> c;    // 일단 옷 종류랑 그 개수를 다 때려박음
    for(int i=0;i<clothes.size();i++){
        c[clothes[i][1]]++;
    }
    
    int answer = 1;
    
    for(auto p: c){
        answer *= p.second+1;
    }
    answer--;
    
    return answer;
    
}