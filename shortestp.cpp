#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int i = 0;
        int j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                if (i <= j) {
                    ans = max(ans, j - i);
                }
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Sample input
    vector<int> nums1 = {30, 29, 19, 5};
    vector<int> nums2 = {25, 25, 25, 25, 25};
    
    int result = sol.maxDistance(nums1, nums2);
    cout << "Maximum Distance: " << result << endl;

    return 0;
}
