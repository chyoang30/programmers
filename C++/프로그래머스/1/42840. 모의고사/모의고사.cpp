#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    // 1번 수포자: 12345 반복 -> 5
    // 2번 수포자: 21232425 반복 -> 8
    // 3번 수포자: 3311224455 반복 -> 10
    
    int guess1[5] = {1, 2, 3, 4, 5};
    int guess2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int guess3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    // 1, 2, 3번의 정답 개수를 적을 변수
    int score[3] = {0};
    
    // 정답 확인하면서 몇 개 맞췄는지 셀 반복문
    for(int i=0; i<answers.size();i++){
        int ans = answers[i];
        if(guess1[i%5]==ans) score[0]++;
        if(guess2[i%8]==ans) score[1]++;
        if(guess3[i%10]==ans) score[2]++;
    }
    
    // 가장 높은 점수 받은 사람을 answer 배열에 넣기
    // 가장 높은 점수를 받은 사람이 여럿일 경우, 오름차순으로 정렬 ex) [1, 2]
    // 이거 어려운데...? 큰 값을 구할 수는 있어도 그 가장 큰 값의 인덱스는 어떻게 구하지? 점수가 같은 경우는 어떻게 처리?
    vector<int> answer;
    
    // 이렇게 하나하나 조건문으로 처리...?
    // if(score[0]>score[1]) {
    //     if(score[0]>score[2]) answer.push_back(1);
    // }
    // 아닌 것 같음... 주석 처리로 잠시 지워둠
    
    // 일단 가장 큰 값을 구하자
    int maxScore = max(score[0], score[1]);
    maxScore = max(maxScore, score[2]);
    
    // 그리고 그 값의 인덱스를 구하고 +1 해서 넣으면 되나?
    for(int i=0;i<3;i++){
        if(score[i]==maxScore){
            answer.push_back(i+1);
        }
    }
    
    return answer;
}