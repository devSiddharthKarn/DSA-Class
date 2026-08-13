#include "iostream"
#include "vector"

void heapify(std::vector<int>&arr,int i){
    if(i<0 || i>=arr.size()) return;

    int l = 2*i+1;
    int r = 2*i+2;

    int max=i;

    if(l<arr.size() && arr[l]>arr[max]){
        max = l;
    }

    if(r<arr.size() && arr[r]>arr[max]){
        max = r;
    }

    if (max==i) return;

    std::swap(arr[max],arr[i]);
    heapify(arr,max);
}

int main(){
    std::vector<int>array={4,1,3,2,16,9,10,14,8};
    heapify(array,0);

    for(int& element:array){
        std::cout<<element<<"\t";
    }

    return 0;
}