#include <string>
#include <vector>

using namespace std;

int solution(int hp) {
    int left_hp = hp;
    int general = 0, soldier = 0, worker = 0;
    
    general = left_hp/5;
    left_hp = left_hp%5;
    
    soldier = left_hp/3;
    worker = left_hp%3;\
        
    int answer = general + soldier + worker;
    
    return answer;
}