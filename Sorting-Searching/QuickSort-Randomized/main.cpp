#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int leftIndex = left - 1;

    for (int i = left; i < right; ++i) {
        if (arr[i] <= pivot) {
            ++leftIndex;
            swap(arr[leftIndex], arr[i]);
        }
    }
    swap(arr[leftIndex + 1], arr[right]);

    return leftIndex + 1;
}

int randomized_partition(vector<int>& arr, int left, int right) {
    int randValue = left + rand() % (right - left + 1);
    swap(arr[right], arr[randValue]);

    return partition(arr, left, right);
}

void randomized_Quicksort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = randomized_partition(arr, left, right);
        randomized_Quicksort(arr, left, pivotIndex - 1);
        randomized_Quicksort(arr, pivotIndex + 1, right);
    }
}
int main() {
    vector<int> arr = {9, 8, 7, 6};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    srand(time(0));
    randomized_Quicksort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
