#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int mari = nums.size()/2;   // 가지고 가는 마리 수
    
    unordered_map<int, int> monster;
    
    for(auto n: nums){
        monster[n]++;
    }
    
    /*
    case1: mari = 2
    3: 2
    1: 1
    2: 1
    마리 수보다 종류 수가 많음 -> 마리 수 리턴
    
    case2: mari = 3
    3: 3
    2: 2
    4: 1
    같음 -> 아무거나
    
    case3: mari = 3
    3: 3
    2: 3
    마리 수보다 종류 수가 적음 -> 종류 수 리턴
    */
    
    // 즉, 마리 수와 종류 수 중에 적은 것을 리턴함]
    
    return min(mari, (int)monster.size());
}