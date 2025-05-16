#include <iostream>
#include <vector>
#include <algorithm> // for max
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long sum = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res = max(res, (sum + i) / (i + 1));
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 7, 1, 6, 8};  // Example input
    int result = sol.minimizeArrayValue(nums);
    cout << "Minimized maximum value: " << result << endl;
    return 0;
}
