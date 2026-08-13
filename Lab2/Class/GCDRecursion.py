from timeit import default_timer

start = default_timer()
def gcd(a,b)->int:
    if b==0:
        return a
    else:
        return gcd(b,b%a)

end=default_timer()

num1 = int(input("Enter first number "))
num2 = int(input("Enter second number "))

ans = gcd(num1,num2)
print(f"The gcd is {ans}")
print(f"The time taken is {end-start}")