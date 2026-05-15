#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int hp) {
    vector<int> dp(hp+1, 1001);
    dp[0] = 0;
    
    vector<int> damage = {1, 3, 5};
    
    for(int i=1; i<=hp; i++){
        for(int d:damage){
            if(i >= d && dp[i-d] != 1001){
                dp[i] = min(dp[i], dp[i-d]+1);
            }
        }
    }
    
    return dp[hp];
}
