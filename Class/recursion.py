def fact(n:int):
    if n==0 or n==1:
        return 1
    else:
        return n*fact(n-1)
    
number= 9
ans =  fact(number)
print(f"The factorial of {number} is {ans}")