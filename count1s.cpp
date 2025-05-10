#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, maxLength = 0, zeroCount = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                zeroCount++;
            }
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1};
    int k = 2;

    int result = solution.longestOnes(nums, k);
    cout << "Longest subarray with at most " << k << " zeroes: " << result << endl;

    return 0;
}
