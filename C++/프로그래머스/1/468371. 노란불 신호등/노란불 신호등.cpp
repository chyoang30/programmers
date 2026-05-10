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
    vector<int> cycle;
    
    for(int i=0;i<signals.size();i++){
        cycle.push_back(signals[i][0] + signals[i][1] + signals[i][2]);
    }
    
    long long total_lcm = 1;
    for(int i=0;i<cycle.size();i++){
            total_lcm = lcm(total_lcm, cycle[i]);
    }
    
    int g0 = signals[0][0], y0 = signals[0][1];
    int p0 = cycle[0];
    
    for(int t=1;t<=total_lcm;t++){
        vector<bool> isYellow(signals.size());
        for(int i=0;i<signals.size();i++){
            int p = t%cycle[i];
            if(p==0) p==cycle[i];
            if(p>signals[i][0]&&p<=signals[i][0]+signals[i][1])
                isYellow[i] = true;
            else isYellow[i] = false;
        }
        bool allYellow = true;
        for(int i=0;i<signals.size();i++){
            if(!isYellow[i]){
                allYellow = false;
                break;
            }
        }
        
        if(allYellow) return t;
    }
 
    return -1;
}