def solution(a, b):
    if (a%2==0): whatA = False
    else: whatA= True
    if (b%2==0): whatB = False
    else: whatB = True
    
    if (whatA and whatB): return a*a+b*b 
    elif (whatA or whatB): return 2*(a+b)
    else: return abs(a-b)