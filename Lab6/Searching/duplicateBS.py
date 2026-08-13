import math

def binarySearch(arr:list[float],l:int,r:int,target:float):
    if l>r:
        return -1
    else:
        m =math.floor((l+r)/2)
        if arr[m]==target:
            print("Element Found at index:",m)
            binarySearch(arr,l,m-1,target)
            binarySearch(arr,m+1,r,target)
        elif target>arr[m]:
            binarySearch(arr,m+1,r,target)
        else:
            binarySearch(arr,l,m-1,target) 


def binarySearchLinear(A:list[float],l:int,r:int,target:float):
    arr:list[int]=[]
    m:int
    while(l<=r):
        m=math.floor((l+r)/2)

        if(A[m]==target):
            arr.append(m)
            break
        elif target>arr[m]:
            l=m+1
        else:
            r=m-1

    
    

arr:list[float]=[1,2,3,3,3,3,3,4,5]

binarySearch(arr,0,len(arr)-1,3)