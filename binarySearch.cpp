#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target)
            return mid;
        else if (target > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter the number of elements for the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int target;
    cout << "Enter the target to search for: ";
    cin >> target;

    int result = binarySearch(arr, n, target);
    if (result != -1)
        cout << "Target found at index " << result << endl;
    else
        cout << "Target not found in the array." << endl;

    return 0;
}
