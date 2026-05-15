#include <string>
#include <vector>

using namespace std;

long long solution(int k, int d) { // k=2, d=4
    long long answer = 0;
    long long y = (long long)(d/k)*k; // y의 최댓값
    
    for(long long x=0;x<=d;x+=k){
        
        while(x*x+y*y>(long long)d*d){ // 점이 원을 벗어나면 반복
            y -= k; // y값 줄이기
        }   // 점이 원 안에 들어오면 종료
        
        /*
        ex)
        k=2, d=5 라면, y는 4부터 시작
        x=4일 때 y=4는 불가, y=2에서 반복문 종료, 즉 y = 0, 2가 가능 -> answer에 +2
        x=2일 때 y=4에서 반복문 종료, y = 0, 2, 4 -> answer에 +3
        */
        
        answer += y/k + 1;
        
    }
    
    return answer;
}