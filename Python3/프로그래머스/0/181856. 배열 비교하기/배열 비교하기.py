def solution(arr1, arr2):
    len1 = len(arr1)
    len2 = len(arr2)
    
    if (len1>len2): return 1
    if (len1<len2): return -1

    sum1 = sum(x for x in arr1)
    sum2 = sum(x for x in arr2)
    
    if (sum1>sum2): return 1
    if (sum1<sum2): return -1
    
    return 0