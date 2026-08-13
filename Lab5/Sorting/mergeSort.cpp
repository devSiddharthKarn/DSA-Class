#include <iostream>
#include <vector>
#include "chrono"

using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r)
        return;

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
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
    mergeSort(arr,0,n);
    auto end = std::chrono::high_resolution_clock::now();

    // display(arr,n);

    auto time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);

    std::cout<<"Time taken:"<<time_taken.count()*1e-9<<"s";

    return 0;

    return 0;
}