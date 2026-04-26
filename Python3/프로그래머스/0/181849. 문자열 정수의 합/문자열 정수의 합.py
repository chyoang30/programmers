def solution(num_str):
    leng = len(num_str)
    temp = int(num_str)
    answer = 0
    for i in range(leng):
        ten = 10**(leng-1-i)
        div = temp//ten
        answer += div
        temp -= ten*div
    return answer