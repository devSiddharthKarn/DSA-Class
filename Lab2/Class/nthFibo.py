from timeit import default_timer

a = 1
b = 1

start = default_timer()
def fibo(n):
    if n==1 or n==2:
        return 1
    else:
        return fibo(n-1) + fibo(n-2)

n = 44
ans = fibo(n)
end=default_timer()
print(ans)
print(f"Time taken:{end-start}")