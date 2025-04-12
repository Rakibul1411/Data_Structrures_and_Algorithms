#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int median(vector<int>& arr, int left, int right) {
    int center = (left + right) / 2;
    if (arr[left] > arr[center])
        swap(arr[left], arr[center]);
    if (arr[left] > arr[right])
        swap(arr[left], arr[right]);
    if (arr[center] > arr[right])
        swap(arr[center], arr[right]);

    swap(arr[center], arr[right - 1]);
    return arr[right - 1];
}

void quickSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        if (right - left >= 2) {
            int pivot = median(arr, left, right);
            int leftIndex = left+1;
            int rightIndex = right-2;

            while(true) {
                while (arr[leftIndex] < pivot) {
                    ++leftIndex;
                }
                while (arr[rightIndex] > pivot) {
                    --rightIndex;
                }
                if (leftIndex < rightIndex) {
                    swap(arr[leftIndex], arr[rightIndex]);
                } else {
                    break;
                }
            }

            swap(arr[leftIndex], arr[right-1]);

            quickSort(arr, left, leftIndex-1);
            quickSort(arr, leftIndex+1, right);
        }
        else {
            if (arr[left] > arr[right]) {
                swap(arr[left], arr[right]);
            }
        }
    }
}

int main() {
    vector<int> arr = {13, 81, 10, 43, 31, 75, 0, 92};

    quickSort(arr, 0, arr.size()-1);

    cout << "After Quick Sort: " << endl;
    for(int value: arr) {
        cout << value << " ";
    }
    return 0;
}
