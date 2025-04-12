#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSortWithNegatives(vector<int>& arr) {
    if (arr.empty()) return;

    int maxValue = *max_element(arr.begin(), arr.end());
    int minValue = *min_element(arr.begin(), arr.end());
    int range = maxValue - minValue + 1;

    vector<int> count(range, 0);
    vector<int> output(arr.size());

    for(int num: arr) {
        count[num - minValue]++;
    }

    for(int i=1; i<range; ++i) {
        count[i] += count[i-1];
    }

    for(int j=arr.size() - 1; j >= 0; --j) {
        output[count[arr[j] - minValue] - 1] = arr[j];
        count[arr[j] - minValue]--;
    }

    for(int i=0; i<arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    vector<int> arr = {-2, 5, 3, -1, 2, 3, 0, -3, -3, -2, -2, -2, 0, -3, 0, 0, -4, -5};

    countingSortWithNegatives(arr);

    cout << "After Counting Sort: " << endl;
    for (int value : arr) {
        cout << value << " ";
    }
    return 0;
}