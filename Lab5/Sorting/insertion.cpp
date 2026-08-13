#include "iostream"
#include "vector"

inline void insertionSort(std::vector<int>& arr){
    int length = arr.size();
    for(int i=1;i<length;i++){
        int index =i;
        while(index>0){
            if(arr[index-1]>arr[index]){
                std::swap(arr[index-1],arr[index]);
            }else break;
            index--;
        }
    }
}

int main(){
    std::vector<int> array={23,12,45,67};

    insertionSort(array);

    for(int i=0;i<array.size();i++){
        std::cout<<array[i]<<"\t";
    }

    return 0;
}