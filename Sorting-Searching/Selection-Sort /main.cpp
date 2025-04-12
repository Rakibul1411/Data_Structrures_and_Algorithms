#include <iostream>
#include <vector>]
using namespace std;

void selectionSort(vector<int>& arr) {
    int size = arr.size();

    for (int i = 0; i < size; ++i) {
        int minIndex = i;
        //int minValue = arr[minIndex];

        for (int j = i+1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    vector<int> arr = {77, 33, 44, 11, 88, 22};

    selectionSort(arr);

    cout << "After Selection Sort: " << endl;

    for(int value: arr) {
        cout << value << " ";
    }

    return 0;
}
