#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int>& arr) {
    int size = arr.size();
    for (int i = 1; i < size; ++i) {
        int temp = arr[i];

        int j = i - 1;

        while( j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = temp;
    }
}

int main() {
    vector<int> arr = {77, 33, 44, 11, 88, 22};

    insertionSort(arr);

    cout << "After Insertion Sort: " << endl;
    for(int value: arr) {
        cout << value << " ";
    }

    return 0;
}
