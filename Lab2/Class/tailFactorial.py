# finding factorial using tail recursion

def fact(n,accum):
    if n==0 or n==1:
        return accum
    else:
        return fact(n-1,accum=accum*n)


number = 9
result = fact(number,1)
print(result)