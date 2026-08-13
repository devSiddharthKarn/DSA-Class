#include <iostream>
#include <vector>
#include "chrono"

using namespace std;

void shellSort(vector<int>& arr) {
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

int main() {
    int n;
    std::cout<<"Enter n:";
    std::cin>>n;
    std::vector<int>arr(n);
    for(int i=0;i<n;i++){
        arr[i]=rand()%100000;
    }

    // display(arr,n);

    auto start = std::chrono::high_resolution_clock::now();
    shellSort(arr);
    auto end = std::chrono::high_resolution_clock::now();

    // display(arr,n);

    auto time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);

    std::cout<<"Time taken:"<<time_taken.count()*1e-9<<"s";

    return 0;
}