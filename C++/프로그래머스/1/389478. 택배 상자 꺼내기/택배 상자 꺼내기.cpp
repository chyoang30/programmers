#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    /*
    행렬을 사용한 풀이, 맨 아래 행을 0층이라고 함
    1. 먼저 행(row)을 구함: (num-1) / w, ex) 8/6=1행
    2. 열(col) 구하기: 짝수 행과 홀수 행의 계산이 달라짐
        2-1. 짝수 행: (num-1)%w, ex) (5-1)%6=4열
        2-2. 홀수 행: w-1-((num-1)%w), ex) 6-1-((8-1)%6)=4열
    3. n <= 100의 제한 -> 적은 개수, 모든 상자의 좌표를 검사하는 것이 효율적일 것으로 보임
        n이 w의 배수가 아닌 경우 마지막 행이 불완전 -> 수식 대신 실존하는 상자(1~n)만 순회하여 안전하게 처리 (상자 개수가 적어서 가능)
    */
    
    int answer = 0; // 꺼내려는 상자와 같은 열이면서 행 수가 큰 상자의 개수를 적을 것임
    
    int row = 0;
    int col = 0 ;
    row = (num-1)/w;
    if(row%2==0) col = (num-1)%w;
    else col = w-1-((num-1)%w);
    // 꺼내려는 상자의 좌표 (row, col)
    
    
    for(int i=1;i<=n;i++){ // 모든 상자의 좌표를 검사하며 같은 열&&더 위에 있는 상자와 본인의 개수를 세서 총 꺼내야 하는 상자의 개수를 구함
        int temp_row = (i-1)/w;
        int temp_col = 0;
        if(temp_row%2==0) temp_col = (i-1)%w;
        else temp_col = w-1-((i-1)%w);
        
        if(temp_col==col && temp_row>=row) answer++;
    }

    return answer;
}