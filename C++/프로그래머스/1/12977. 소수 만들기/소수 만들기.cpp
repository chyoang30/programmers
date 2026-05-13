#include <vector>
#include <iostream>
using namespace std;

// 소수 여부를 확인하는 함수
bool isPrime(int n){
    if(n==1) return false;
    int answer = 0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) answer++;
    }
    if(answer==0) return true;
    else return false;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    int length = nums.size();
    
    // 주어진 배열 nums에서 3개의 숫자를 골라 더하는 경우의 수
    int i, j, k;
    int sum;
    
    for(i=0;i<length-2;i++){
        sum = 0;
        for(j=i+1;j<length-1;j++){
            for(k=j+1;k<length;k++){
                sum = nums[i]+nums[j]+nums[k];
                if(isPrime(sum)) answer++;
            }
        }
    }

    return answer;
}
