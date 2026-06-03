#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxW= 0;
    int maxH= 0;
    
    /*
    [[10, 7], [12, 3], [8, 15], [14, 7], [5, 15]]
    1. (10, 7): 10*7
    2. (12, 3): 12*7
    3. (15, 8): 15*8
    4. (14, 7): 15*8
    5. (15, 5): 15*8 -> 120
    
    [[14, 4], [19, 6], [6, 16], [18, 7], [7, 11]]
    1. (14, 4): 14*4
    2. (19, 6): 19*6
    3. (16, 6): 19*6
    4. (18, 7): 19*7
    5. (11, 7): 19*7 -> 133
    
    순회를 통해 가장 큰 너비와 높이 값을 찾되, 너비가 높이보다 작은 경우 돌려서 확인하기
    */
    
    
    for(int i=0;i<sizes.size();i++){    // 1. 일단 전체를 순회하면서 가장 큰 너비, 높이 값을 찾는다.
        int tempW = sizes[i][0]; // 일단 현재 너비, 높이 쌍을 임시 변수에 넣고
        int tempH = sizes[i][1];
        
        if(tempW<tempH){    // 너비가 높이보다 작으면 스왑
            int temp = tempW;
            tempW = tempH;
            tempH = temp;
        }
        
        if(tempW>maxW) maxW = tempW;  // 그리고 비교해서 가장 큰 수로 끼워넣기
        if(tempH>maxH) maxH = tempH;
    }
    
    return maxW*maxH;
    
}