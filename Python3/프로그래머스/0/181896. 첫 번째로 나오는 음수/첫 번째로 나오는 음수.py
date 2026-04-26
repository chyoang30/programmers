def solution(num_list):
    leng = len(num_list)
    for i in range(leng):
        if (num_list[i]<0): return i
    return -1