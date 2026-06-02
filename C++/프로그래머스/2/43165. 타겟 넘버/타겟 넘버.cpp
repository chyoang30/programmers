#include <string>
#include <vector>

using namespace std;

// DFS 문제인데, 그래프가 아니라 트리의 형태를 가짐
/*
ex) {1, 2}
        시작       // index = 0
       /   \        
     -1    +1     // index = 1
     / \   / \
   -2  +2 -2 +2   // index = 2
*/

int dfs(int sum, int index, vector<int> numbers, int target) {
    if(index==numbers.size()){  // 트리 끝에 도달했을때(재귀함수 종료 조건)
        if(sum==target){    // 타겟 넘버가 나오면
            return 1;
        }
        else
            return 0;       // 타겟 넘버가 아니면
    }
    
    // 종료 조건 미달성시
    // dfs(현재 숫자 더하는 경우) + dfs(현재 숫자 빼는 경우)
    return (dfs(sum+numbers[index], index+1, numbers, target)+dfs(sum-numbers[index], index+1, numbers, target));
}

int solution(vector<int> numbers, int target) {
    return dfs(0, 0, numbers, target);
}