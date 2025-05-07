#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        // Count positives
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) right = mid - 1;
            else left = mid + 1;
        }
        int positiveCount = n - left;

        // Reset left and right to count negatives
        left = 0;
        right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) left = mid + 1;
            else right = mid - 1;
        }
        int negativeCount = right + 1;

        return max(positiveCount, negativeCount);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-3, -2, -1, 0, 0, 1, 2, 3};
    cout << "Maximum Count: " << sol.maximumCount(nums) << endl;
    return 0;
}
