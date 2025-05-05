#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                return mid;
            else if (arr[mid - 1] > arr[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1; // Should never be reached in valid mountain array
    }
};

int main() {
    Solution sol;
    vector<int> arr = {0, 2, 4, 6, 5, 3, 1};
    int peakIndex = sol.peakIndexInMountainArray(arr);
    cout << "Peak Index: " << peakIndex << endl;
    return 0;
}
