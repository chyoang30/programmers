def solution(number):
    sum_num = 0
    for i in number:
        sum_num += int(i)
    answer = sum_num%9
    
    return answer