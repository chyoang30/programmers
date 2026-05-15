#include <string>
#include <vector>
#include <algorithm> // sort를 위해 필수

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    sort(sides.begin(), sides.end()); // 정렬해서 인덱스 0이 짧은 변, 1이 긴 변으로
    
    // case 1: 가장 긴 변이 sides[1]인 경우, sides[0]+i > sides[1]
    for(int i=sides[1];i+sides[0]>sides[1];i--){
        answer++;
    }
    
    // case 2: 가장 긴 변이 sides에 없는 경우
    for(int i=sides[1]+1;i<sides[0]+sides[1];i++){
        answer++;
    }
    
    return answer;
}