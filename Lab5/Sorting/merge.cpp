#include "iostream"
#include "vector"


void merge(std::vector<int>& arr,int left,int mid,int right){

    int first = left; //must be <=mid 
    int second = mid+1; //must be <=right

    std::vector<int> merged;
    merged.resize(right-left+1);
    int writePointer=0;

    while(first<=mid && second<=right){
        while(first<=mid ){
            if(arr[first]<=arr[second]){
                merged[writePointer++]=arr[first++];
            }else break;
        }

        while(second<=right && first<=mid){
            if(arr[second]<=arr[first]){
                merged[writePointer++]=arr[second++];
            }else break;
        }
    }

    while(first<=mid){
        merged[writePointer++]=arr[first++];
    }

    while(second<=right){
        merged[writePointer++]=arr[second++];
    }

    int copyPointer=left;
    for(int i=0;i<merged.size();i++){
        arr[copyPointer++]=merged[i];
    }
}


void mergeSort(std::vector<int>& arr,int left,int right){

    if(left>=right) return;

    int mid = left+(right-left)/2;

    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

int main(){
    std::vector<int> arr={1,7,2,1,0,45,21};

    mergeSort(arr,0,arr.size()-1);

    for(int i=0;i<arr.size();i++){
        std::cout<<arr[i]<<"\t";
    }

    return 0;
}