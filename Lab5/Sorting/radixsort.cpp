#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Count occurrences
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Prefix sum
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output array
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;

        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int maxElement = arr[0];

    for (int x : arr) {
        maxElement = max(maxElement, x);
    }

    // exp = 1 -> units
    // exp = 10 -> tens
    // exp = 100 -> hundreds
    for (int exp = 1; maxElement / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(arr);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}