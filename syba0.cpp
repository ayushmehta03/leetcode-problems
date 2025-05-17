#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, maxLen = 0;
        unordered_map<int, int> seen;  // maps prefix sum to its first index
        seen[0] = -1;  // base case: prefix sum 0 before index 0

        for (int i = 0; i < nums.size(); i++) {
            // Convert 0 to -1 to balance with 1s
            sum += nums[i] == 1 ? 1 : -1;

            if (seen.count(sum)) {
                // If the same sum was seen before, the subarray in between sums to 0
                maxLen = max(maxLen, i - seen[sum]);
            } else {
                // Store first occurrence of this sum
                seen[sum] = i;
            }
        }

        return maxLen;
    }
};

// 🔹 Example usage
int main() {
    Solution solution;
    vector<int> nums = {0, 1, 0, 1, 1, 0, 0};
    cout << "Maximum length of subarray with equal 0s and 1s: "
         << solution.findMaxLength(nums) << endl;
    return 0;
}
