#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void merge(vector<int>& arr, int lower, int midPoint, int upper) {
    int size1 = midPoint - lower + 1;
    int size2 = upper - midPoint;

    vector<int> leftArray(size1);
    vector<int> rightArray(size2);

    for (int i = 0; i < size1; i++) {
        leftArray[i] = arr[lower + i];
    }

    for (int j = 0; j < size2; j++) {
        rightArray[j] = arr[midPoint + 1 + j];
    }

    leftArray.push_back(INT_MAX);
    rightArray.push_back(INT_MAX);

    int i = 0;
    int j = 0;

    for (int k = lower; k <= upper; k++) {
        if (leftArray[i] <= rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        }
        else {
            arr[k] = rightArray[j];
            j++;
        }
    }
}

void mergeSort(vector<int>& arr, int lower, int upper) {
    if (lower < upper) {
        int midPoint = (lower + upper) / 2;

        mergeSort(arr, lower, midPoint);
        mergeSort(arr, midPoint + 1, upper);

        merge(arr, lower, midPoint, upper);
    }
}

int main() {
    vector<int> arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    mergeSort(arr, 0, arr.size() - 1);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
