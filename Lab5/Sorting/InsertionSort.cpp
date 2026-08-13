#include "iostream"
#include "chrono"

#define MAX 500000

void swap(int& p, int& q){
    int temp=p;
    p=q;
    q=temp;
}

void display(int arr[],int n){
    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

void insertionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i-1;
        int temp=arr[i];
        while(j>=0 && temp<arr[j]){
            swap(arr[j+1],arr[j]);
            j=j-1;
        }
        arr[j+1]=temp;
    }
}

int main(){
    int i,n,arr[MAX];

    std::cout<<"Enter n:";
    std::cin>>n;
    for(i=0;i<n;i++){
        arr[i]=rand()%100000;
    }

    // display(arr,n);

    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(arr,n);
    auto end = std::chrono::high_resolution_clock::now();

    // display(arr,n);

    auto time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);

    std::cout<<"Time taken:"<<time_taken.count()*1e-9<<"s";

    return 0;
}
