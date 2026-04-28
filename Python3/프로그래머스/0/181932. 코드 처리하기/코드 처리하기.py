def solution(code):
    mode = 0
    ret = ''
    
    for i, v in enumerate(code):
        if v=="1":
            mode = 1 - mode
        else:
            if mode==0 and i%2==0: ret += v
            if mode==1 and i%2==1: ret += v
            
    return ret if ret else "EMPTY"