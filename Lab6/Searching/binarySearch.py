import timeit
import sys
import random

def binarySearch(arr:list[float],target:float):
    left:int =0
    right:int = len(arr)-1

    while(left<=right):
        mid = left+(right-left)//2
        
        if arr[mid]==target:
            print("Element is found at the index:",mid)
            return
        elif target>arr[mid]:
            left=mid+1
        elif target<arr[mid]:
            right=mid-1

        
    print("Element is not found in the list")

print(sys.argv)
n:int = int(sys.argv[1])
key:int = int(sys.argv[2])

arr:list[float]=[]

for i in range(n):
    number = random.randint(0,1000)
    arr.append(number)

arr.sort()
startTime = timeit.default_timer()
binarySearch(arr,key)
endTime = timeit.default_timer()

print(f"The time taken is {endTime-startTime} seconds")