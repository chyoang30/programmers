#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool isPrime(int n){     // 정수를 입력받아 소수인지 판별하는 함수
    // 소수: 1과 자기자신 외에 나눌 수 없는 숫자
    // 일단 0, 1이면 소수가 아님
    if(n==0 or n==1) return false;
    
    /*
    2~n-1의 수로 나눠서 나머지가 0이 되는 경우가 있으면 소수가 아님
    근데 반복 횟수를 좀 줄일 수 없을까?
    12의 경우 12/2=6, 12의 약수는 자신과 1을 제외하면 2, 3, 4, 6
    24의 경우 24/2=12, 24의 약수는 자신과 1을 제외하면 2, 3, 4, 6, 8, 12
    -> 자기 자신의 반절을 넘어가면 본인 제외 약수가 나오지 않는 것은 당연함
    소수인 11, 13은 반복문을 끝까지 돌텐데 각각 5, 6을 넘어가면 반복문을 종료하는 것이 더 효율적이지 않을까 O(n)->O(n/2) 이렇게
    */
    
    for(int i=2;i<=n/2;i++){
        if(n%i==0) return false;
    }
    
    // 반복문 통과 시 소수로 판명
    return true;
}

/*
    "123"이라면 1, 2, 3, 12, 13, 21, 23, 31, 32, 123, 132, 213, 231, 312, 321가 있음
    
    트리 구조로 풀어보면
             시작
          /   |   \
         1    2    3
        / \  / \  / \
       12 13
       |  |
      123 132 (옆 부분 생략)
     -> 이런 느낌
     
     근데 말단만 보는 게 아니라 1, 12, 123 전부 확인해야 함
     -> dfs?
*/

bool visited[7];    // 몇 번째 숫자의 사용 여부를 저장하는 배열, "123"에서 1을 사용하면 visited[0]에 true
unordered_set<int> set;     // 여기는 만든 숫자를 저장. 집합을 쓸 거임. 집합은 중복 비허용이기 때문

void dfs(string current, string numbers){
    if(current!="") {
        set.insert(stoi(current));    // 비어있지 않다면 집합에 넣기
    }
    
    for(int i=0;i<numbers.size();i++){
        if(!visited[i]) {
            string next = current + numbers[i]; // i=0 -> next = "1"
            visited[i] = true;  // 사용으로 표시
            set.insert(stoi(next));
            dfs(next, numbers);
            visited[i] = false;  // 사용 해제
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    dfs("", numbers);
    
    for(auto i: set){
        if(isPrime(i)) answer++;
    }
    
    return answer;
}