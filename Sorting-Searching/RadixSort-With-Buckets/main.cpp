#include <iostream>
#include <vector>
using namespace std;

int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

void radixSortWithBuckets(vector<int>& arr) {
    int max = getMax(arr);

    for(int base=1; max / base > 0; base*=10) {
        vector<vector<int>> buckets(10);

        for(int num: arr) {
            int digit = (num / base) % 10;
            buckets[digit].push_back(num);
        }

        int index = 0;
        for(int i=0; i < 10; ++i) {
            for(int num: buckets[i]) {
                arr[index++] = num;
            }
        }
    }
}

void printArray(const vector<int>& arr) {
    for(int num: arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Original array:" << endl;
    printArray(arr);

    radixSortWithBuckets(arr);
    
    cout << "Sorted array:" << endl;
    printArray(arr);

    return 0;
}
