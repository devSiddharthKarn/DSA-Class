import sys
import random
import timeit

def linearSearch(arr:list[int],target:float):

    for i in range(len(arr)):
        if arr[i]==target:
            print(f"Element found at index {i}")
        
    print("Element not found")
    return


n = int(sys.argv[1])
key =int(sys.argv[2])

arr:list[int]=[]
for _ in range(n):
    arr.append(random.randint(1,10000))

startTime = timeit.default_timer()
linearSearch(arr,key)
endTime = timeit.default_timer()

print("The time taken is:",(endTime-startTime)," seconds")