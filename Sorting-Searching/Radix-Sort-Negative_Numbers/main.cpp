#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

void radixSortWithBuckets(vector<int>& arr) {
    if (arr.empty()) return;

    int min_val = *min_element(arr.begin(), arr.end());
    int offset = (min_val < 0) ? -min_val : 0;

    for (int& num : arr) num += offset;

    int max = getMax(arr);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        vector<vector<int>> buckets(10);

        for (int num : arr) {
            int digit = (num / exp) % 10;
            buckets[digit].push_back(num);
        }

        int index = 0;
        for (auto& bucket : buckets) {
            for (int num : bucket) {
                arr[index++] = num;
            }
        }
    }

    for (int& num : arr) num -= offset;
}

void printArray(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    vector<int> arr = {170, 45, 75, -90, 802, -24, 2, 66, -123, -1};

    cout << "Original array:" << endl;
    printArray(arr);

    radixSortWithBuckets(arr);

    cout << "Sorted array:" << endl;
    printArray(arr);

    return 0;
}