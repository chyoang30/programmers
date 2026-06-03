#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
brown, yellow가 (24, 24)라고 하면
brown+yellow의 약수 쌍: (48, 1), (24, 2), (16, 3), (12, 4), (8, 6)
(가로가 길다고 명시되어 있음)

여기서 b+y의 쌍에서 (가로-2)*(세로-2) 했을 때 yellow의 값과 같다면 정답
*/

vector<vector<int>> aliquot_pair(int n){ // 그래서 일단 약수 쌍을 구하는 함수를 만들어봄
    // 약수 쌍은 √n 까지만 검사하면 시간을 아낄 수 있음
    // 예시: √24는 4.89....인데 약수 쌍은 (24, 1), (12, 2), (8, 3), (6, 4)로 작은 수가 4를 넘지 않음
    vector<vector<int>> ans;    // <- 이 2차원 배열에 약수 쌍을 저장할 것임
    
    for(int i=1;i*i<=n;i++){ // i*i<n: 이 조건을 걸어두어 √n까지만 검사하게 할 것임
        if(n%i==0){
            ans.push_back({n/i, i});    // i=1: {48, 1}를 2차원 배열에 넣음, {24, 2}, {16, 3}...
        }
    }
    
    return ans;
}

vector<int> solution(int brown, int yellow) {
    vector<vector<int>> sum_pair = aliquot_pair(brown+yellow);  // 약수 쌍을 2차원 배열에 저장
    
    for(int i=0;i<sum_pair.size();i++){
        int w = sum_pair[i][0]-2;
        int h = sum_pair[i][1]-2;   // sum_pair[i] = {8, 6}이라면, (w, h)에 {6, 4}를 넣음   
        
        if(w*h == yellow){
            return sum_pair[i];
        }
    }
}