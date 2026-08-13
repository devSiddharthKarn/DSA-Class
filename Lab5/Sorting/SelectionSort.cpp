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

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int least = arr[i];
        int pos =i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<least){
                least=arr[j];
                pos=j;
            }
        }
        if(i!=pos){
            swap(arr[i],arr[pos]);
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
    selectionSort(arr,n);
    auto end = std::chrono::high_resolution_clock::now();

    // display(arr,n);

    auto time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);

    std::cout<<"Time taken:"<<time_taken.count()*1e-9<<"s";

    return 0;
}
