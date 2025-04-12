#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int left, int right) {
    int pivotValue = arr[right];
    int leftIndex = left - 1;
    for (int j = left; j <= right - 1; ++j) {
        if (arr[j] <= pivotValue) {
            leftIndex++;
            swap(arr[leftIndex], arr[j]);
        }
    }
    swap(arr[leftIndex + 1], arr[right]);

    return leftIndex + 1;
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main() {
    vector<int> arr = {2, 5, 8, 3, 9, 4, 1, 7, 10, 6, 2, 5, 8, 3, 9, 4, 1, 7, 10, 6};

    quickSort(arr, 0, arr.size() - 1);

    cout << "After Quick Sort: " << endl;
    for(int value: arr) {
        cout << value << " ";
    }


    return 0;
}
