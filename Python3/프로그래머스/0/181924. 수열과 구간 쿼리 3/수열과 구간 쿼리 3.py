def solution(arr, queries):
    for x in range(len(queries)):
        i = queries[x][0]
        j = queries[x][1]
        arr[i], arr[j] = arr[j], arr[i]
    
    return arr