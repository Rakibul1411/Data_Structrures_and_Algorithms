#include <iostream>
#include <vector>

using namespace std;

// Function to print array
void printArray(const vector<int>& arr, int left, int right) {
    cout << "[ ";
    for (int i = 0; i < arr.size(); i++) {
        if (i >= left && i <= right) {
            cout << arr[i];
        } else {
            cout << ".";  // Dots for elements not in current partition
        }
        if (i < arr.size() - 1) cout << " ";
    }
    cout << " ]" << endl;
}

// Function to swap two elements and record the swap
void swap(int &a, int &b, vector<int>& arr, int i, int j) {
    cout << "  Swap arr[" << i << "]=" << a << " with arr[" << j << "]=" << b << endl;
    int temp = a;
    a = b;
    b = temp;
    printArray(arr, 0, arr.size() - 1);
}

// Median function with detailed output
int median(vector<int> &arr, int left, int right) {
    int center = (left + right) / 2;

    cout << "Finding median of three: arr[" << left << "]=" << arr[left]
         << ", arr[" << center << "]=" << arr[center]
         << ", arr[" << right << "]=" << arr[right] << endl;

    if (arr[left] > arr[center]) {
        swap(arr[left], arr[center], arr, left, center);
    }
    if (arr[left] > arr[right]) {
        swap(arr[left], arr[right], arr, left, right);
    }
    if (arr[center] > arr[right]) {
        swap(arr[center], arr[right], arr, center, right);
    }

    cout << "  After sorting three elements: "
         << arr[left] << " <= " << arr[center] << " <= " << arr[right] << endl;

    // Swap center with right-1
    swap(arr[center], arr[right - 1], arr, center, right - 1);

    cout << "  Pivot value: " << arr[right - 1] << " at index " << (right - 1) << endl;
    return arr[right - 1];
}

// QuickSort function with detailed tracing
void quicksort(vector<int> &arr, int left, int right, int depth = 0) {
    string indent(depth * 2, ' ');
    cout << indent << "Quicksort called on subarray [" << left << "..." << right << "]:" << endl;
    printArray(arr, left, right);

    if (left < right) {
        if (right - left >= 2) {
            cout << indent << "Using median-of-three pivot selection" << endl;
            int pivot = median(arr, left, right);

            int i = left + 1;
            int j = right - 2;
            cout << indent << "Beginning partitioning with pivot=" << pivot << endl;
            cout << indent << "Initial i=" << i << ", j=" << j << endl;

            while (true) {
                while (arr[i] < pivot) {
                    cout << indent << "  i moves to " << i << " (arr[" << i << "]=" << arr[i] << ")" << endl;
                    ++i;
                }
                cout << indent << "  i stops at " << i << " (arr[" << i << "]=" << arr[i] << " >= " << pivot << ")" << endl;

                while (arr[j] > pivot) {
                    cout << indent << "  j moves to " << j << " (arr[" << j << "]=" << arr[j] << ")" << endl;
                    --j;
                }
                cout << indent << "  j stops at " << j << " (arr[" << j << "]=" << arr[j] << " <= " << pivot << ")" << endl;

                if (i < j) {
                    cout << indent << "  i < j, so swap elements:" << endl;
                    swap(arr[i], arr[j], arr, i, j);
                } else {
                    cout << indent << "  i >= j, partitioning complete" << endl;
                    break;
                }
            }

            cout << indent << "Placing pivot in final position:" << endl;
            swap(arr[i], arr[right - 1], arr, i, right - 1);

            cout << indent << "Result after partitioning:" << endl;
            printArray(arr, left, right);
            cout << indent << "Elements < pivot are in positions [" << left << "..." << (i-1) << "]" << endl;
            cout << indent << "Pivot " << arr[i] << " is at position " << i << endl;
            cout << indent << "Elements > pivot are in positions [" << (i+1) << "..." << right << "]" << endl;

            cout << indent << "Recursively sorting left partition [" << left << "..." << (i-1) << "]" << endl;
            quicksort(arr, left, i - 1, depth + 1);
            cout << indent << "Recursively sorting right partition [" << (i+1) << "..." << right << "]" << endl;
            quicksort(arr, i + 1, right, depth + 1);
        }
        else {
            cout << indent << "Subarray has <= 2 elements, direct comparison:" << endl;
            if (arr[left] > arr[right]) {
                swap(arr[left], arr[right], arr, left, right);
            } else {
                cout << indent << "  No swap needed, already in order" << endl;
            }
        }
    } else {
        cout << indent << "Subarray has <= 1 element, nothing to do" << endl;
    }

    cout << indent << "Finished sorting subarray [" << left << "..." << right << "]" << endl;
}

int main() {
    vector<int> arr = {7, 3, 8, 5, 2, 2, 6, 4, 1};

    cout << "Original array: ";
    printArray(arr, 0, arr.size() - 1);

    quicksort(arr, 0, arr.size() - 1);

    cout << "\nFinal sorted array: ";
    printArray(arr, 0, arr.size() - 1);

    return 0;
}
