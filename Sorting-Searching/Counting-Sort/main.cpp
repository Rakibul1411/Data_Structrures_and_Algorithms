#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr) {
    int maxValue = *max_element(arr.begin(), arr.end());
    vector<int> count(maxValue+1, 0);
    vector<int> output(arr.size());

    for (int num : arr) {
        count[num]++;
    }

    for (int i=1; i <= maxValue; ++i) {
        count[i] = count[i-1] + count[i];
    }

    for (int j=arr.size()-1; j >= 0; --j) {
        output[--count[arr[j]]] = arr[j];
    }

    for (int i=0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    vector<int> arr = {2, 5, 3, 0, 2, 3, 0, 3};

    countingSort(arr);

    cout << "After Counting Sort: " << endl;
    for(int value: arr) {
        cout << value << " ";
    }
    return 0;
}
