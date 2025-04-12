#include <iostream>
#include <vector>
using namespace std;

int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    vector<int> leftArray(leftSize);
    vector<int> rightArray(rightSize);

    for (int i = 0; i < leftSize; i++) {
        leftArray[i] = arr[left + i];
    }
    for (int j = 0; j < rightSize; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    int leftIndex = 0, rightIndex = 0;
    int mergedIndex = left;
    int inversionCount = 0;

    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            arr[mergedIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            arr[mergedIndex] = rightArray[rightIndex];
            rightIndex++;
            inversionCount += (leftSize - leftIndex);
        }
        mergedIndex++;
    }

    while (leftIndex < leftSize) {
        arr[mergedIndex] = leftArray[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    while (rightIndex < rightSize) {
        arr[mergedIndex] = rightArray[rightIndex];
        rightIndex++;
        mergedIndex++;
    }

    return inversionCount;
}

int countInversions(vector<int>& arr, int left, int right) {
    int inversionCount = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        inversionCount += countInversions(arr, left, mid);
        inversionCount += countInversions(arr, mid + 1, right);
        inversionCount += mergeAndCount(arr, left, mid, right);
    }
    return inversionCount;
}

int main() {
    vector<int> array = {5, 3, 2, 4, 1};

    int inversionCount = countInversions(array, 0, array.size() - 1);

    cout << "Number of inversions: " << inversionCount << endl;

    cout << "Sorted array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}