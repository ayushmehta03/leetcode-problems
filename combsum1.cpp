#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void makeCombination(vector<int>& candidates, int target, int idx, 
                         vector<int>& comb, int total, 
                         vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(comb);
            return;
        }
        if (total > target || idx >= candidates.size()) {
            return;
        }

        // Include the current element
        comb.push_back(candidates[idx]);
        makeCombination(candidates, target, idx, comb, total + candidates[idx], res);
        comb.pop_back(); // Backtrack

        // Exclude the current element and move to next
        makeCombination(candidates, target, idx + 1, comb, total, res);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        makeCombination(candidates, target, 0, comb, 0, res);
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = sol.combinationSum(candidates, target);

    cout << "Combinations summing to " << target << ":\n";
    for (const auto& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}

