def solution(numLog):
    answer = ''
    
    for i in range(0, len(numLog)-1):
        x = numLog[i+1]-numLog[i]
        
        if x==1: answer += 'w'
        elif x==-1: answer += 's'
        elif x==10: answer += 'd'
        else: answer += 'a'
    
    return answer