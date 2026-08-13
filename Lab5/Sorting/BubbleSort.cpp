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

void bubbleSort(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[i]);
            }
        }
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
    bubbleSort(arr,n);
    auto end = std::chrono::high_resolution_clock::now();

    // display(arr,n);

    auto time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);

    std::cout<<"Time taken:"<<time_taken.count()*1e-9<<"s";

    return 0;
}
