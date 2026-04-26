def solution(str1, str2):
    strlen = len(str1)
    answer = ''
    for i in range(strlen):
        answer += str1[i] + str2[i]
    return answer