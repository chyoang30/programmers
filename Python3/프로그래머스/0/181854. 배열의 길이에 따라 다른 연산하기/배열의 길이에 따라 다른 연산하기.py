def solution(arr, n):
    start = 1 if len(arr)%2==0 else 0
    for i in range(start, len(arr), 2):
        arr[i] += n
    return arr