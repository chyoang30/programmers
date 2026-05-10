#include <string>
#include <vector>

using namespace std;

long long gcd(long long a, long long b){
    return b==0 ? a : gcd(b, a%b);
}


long long lcm(long long a, long long b){
    return a / gcd(a, b) * b;
}


int solution(vector<vector<int>> signals) {
    int size = signals.size();
    vector<int> period;
    
    for(int i=0;i<signals.size();i++){
        period.push_back(signals[i][0] + signals[i][1] + signals[i][2]);
    }
    
    long long total_lcm = 1;
    for(int i=0;i<period.size();i++){
            total_lcm = lcm(total_lcm, period[i]);
    }
    
    int g0 = signals[0][0], y0 = signals[0][1]; // 2, 3
    int p0 = period[0]; // 7
    
    /*
    [testcase 2]
    신호등 0: G=2, Y=3, R=2 → 주기 7
    t:   1   2   3   4    5   6   7
        🟢  🟢  🟡  🟡  🟡  🔴  🔴

    t:   8   9   10  11  12   13  14
        🟢  🟢  🟡  🟡  🟡  🔴  🔴
    
    노란불 시각: 3, 4, 5, 10, 11, 12 ...
    */
    
    for(int c=0; ;c++){ // c: 몇 번째 주기?
        for(int offset=0;offset<y0;offset++){   // offset: 노란 불 중 몇 번째 초?
            
            long long t = c * p0 + g0 + offset + 1; // 지금 시간이자 신호등0이 노란불인 시각
            
            if(t>total_lcm) return -1; // 범위 넘어가면 종료
            
            bool allYellow = true;
            for(int i=0;i<signals.size();i++){
                int p = (t-1)%period[i];
                if(!(p>=signals[i][0]&&p<signals[i][0]+signals[i][1])){
                    allYellow = false;
                    break;
                }
            }
            if(allYellow) return (int)t;
        }
    }
}
