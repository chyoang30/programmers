#include <string>
#include <vector>
#include <algorithm> // sort를 위해 필수

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    sort(sides.begin(), sides.end()); // 정렬해서 인덱스 0이 짧은 변, 1이 긴 변으로
    
    /*
    주어진 두 변이 a, b(a<b)일 때 나머지 변 c를 구하는 문제
    b-a < c < a+b
    
    c의 개수 = (a+b)-(b-a)-1 = 2a-1
    */
    
    return 2*sides[0]-1;
    
}
