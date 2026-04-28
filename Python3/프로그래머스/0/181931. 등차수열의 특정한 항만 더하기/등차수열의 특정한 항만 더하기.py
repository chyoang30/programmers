def solution(a, d, included):
    answer = 0
    
    for i, v in enumerate(included):
        num = a + d*i
        if(v): answer += num
    
    return answer