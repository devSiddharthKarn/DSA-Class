from timeit import default_timer

start = default_timer()
def TOH(n,src,dst,temp):
    if n==1:
        print(f"Move the {n} disk from {src} to {dst}")
    else:
        TOH(n-1,src,temp,dst)
        print(f"Move  the {n} disk from {src} to {dst}")
        TOH(n-1,temp,dst,src)


n = 15
TOH(n,'A','C','B')
print(f"The total number of the steps is {2**n-1}")
end = default_timer()
print(f"The time taken is {end-start}")