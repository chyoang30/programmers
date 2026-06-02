#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> phone;
    
    for(auto p: phone_book){    // 일단 전화번호 다 때려 넣고
        phone[p]++;
    }
    
    /*
    119 -> 1, 11, 119
    97674223 -> 9, 97, 976, ...
    1195524421 -> 1, 11, 119, 1195, ...
    
    이렇게 하나씩 잘라서 map에 있는지 확인 할 거임
    
    이중 반복문으로 문자열을 하나씩 비교하는 방법은?
    -> 이중 반복문의 복잡도는 O(n^2), phone_book의 크기가 최대 100만이기 때문에 100만*100만=1조 회 -> 시간 초과 가능성
    */
    
    // 1. 하나씩 자르는 반복문
    for(int i=0;i<phone_book.size();i++){       // 전화번호 개수만큼 반복
        for(int j=0;j<phone_book[i].size();j++){    // 전화번호 길이만큼 반복 -> 최대 100만*20 = 2000만 회
            if(phone[phone_book[i].substr(0, j)]==1) return false;
        }
    }
    
    return true;
}