def solution(a, b, c, d):
    answer = 0
    arr = [a, b, c, d]
    cnt = {}
    
    for i in arr:
        cnt[i] = cnt.get(i, 0)+1
    
    freq = sorted(cnt.values(), reverse=True)
    
    if freq[0]==4:
        return 1111*arr[0]
    
    elif freq[0]==3:
        p = [k for k, v in cnt.items() if v==3][0]
        q = [k for k, v in cnt.items() if v == 1][0]
        return (10 * p + q) ** 2
    
    elif freq[0] == 2 and freq[1] == 2:
        p, q = sorted([k for k, v in cnt.items() if v == 2])
        return (p + q) * abs(p - q)
    
    elif freq[0] == 2:
        q, r = sorted([k for k, v in cnt.items() if v == 1])
        return q * r
    
    else:
        return min(arr)