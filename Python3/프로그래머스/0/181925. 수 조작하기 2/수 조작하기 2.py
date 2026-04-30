def solution(numLog):
    mapping = {1: 'w', -1: 's', 10: 'd', -10: 'a'}
    key = []
    for i in range(len(numLog)-1):
        key.append(mapping[numLog[i+1]-numLog[i]])
    return ''.join(key)
