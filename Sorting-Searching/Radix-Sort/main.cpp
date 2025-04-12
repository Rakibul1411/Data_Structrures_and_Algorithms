#include <iostream>
#include <vector>
#include <algorithm>

int getMax(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

void countSort(std::vector<int>& arr, int exp) {
    const int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(std::vector<int>& arr) {
    int max = getMax(arr);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    std::cout << "Original array:" << std::endl;
    printArray(arr);

    radixSort(arr);

    std::cout << "Sorted array:" << std::endl;
    printArray(arr);

    return 0;
}