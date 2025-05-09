#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int prevRob = 0;
        int maxRob = 0;
        for (int curValue : nums) {
            int temp = max(maxRob, prevRob + curValue);
            prevRob = maxRob;
            maxRob = temp;
        }
        return maxRob;
    }
};

int main() {
    Solution sol;
    vector<int> houses = {2, 7, 9, 3, 1}; // Example input
    int result = sol.rob(houses);
    cout << "Maximum amount that can be robbed: " << result << endl;
    return 0;
}
