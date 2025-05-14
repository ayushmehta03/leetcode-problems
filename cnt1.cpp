#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }
};

int main() {
    Solution sol;

    // Sample input: every number appears 3 times except one
    vector<int> nums = {2, 2, 3, 2};

    int result = sol.singleNumber(nums);
    cout << "Single Number is: " << result << endl;

    return 0;
}
