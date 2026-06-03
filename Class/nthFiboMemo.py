from timeit import default_timer

table={}

start = default_timer()
def nthFibo(n)->int:
    if n==1 or n==2:
        return 1
    elif n in table:
        return table[n]
    else:
        table[n-1]=nthFibo(n-1)
        table[n-2]=nthFibo(n-2)
        return table[n-1]+table[n-2]
    
n=44
ans = nthFibo(n)
end = default_timer()
print(ans)
print(f"The time taken is {end-start}")