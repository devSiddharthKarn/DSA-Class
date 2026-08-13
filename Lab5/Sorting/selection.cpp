#include "iostream"
#include "vector"

int main(){
    std::vector<int> array={23,12,56,12,67,23,45,86};

    for(int i=0;i<array.size();i++){
        int minIndex = i;
        for(int j=i+1;j<array.size();j++){
            if(array[j]<array[minIndex]){
                minIndex=j;
            }
        }
        std::swap(array[minIndex],array[i]);
    }

    for(const int& element:array){
        std::cout<<element<<"\t";
    }
}