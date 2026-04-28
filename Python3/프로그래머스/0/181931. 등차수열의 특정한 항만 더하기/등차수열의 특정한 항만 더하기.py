def solution(a, d, included):
    answer = 0
    num = a
    
    for v in included:
        if(v): answer += num
        num += d
    
    return answer