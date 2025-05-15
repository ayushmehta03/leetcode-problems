#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        // Grouping anagrams by sorted string key
        for (auto it : strs) {
            string temp = it;
            sort(it.begin(), it.end());
            mp[it].push_back(temp);
        }

        vector<vector<string>> ans;
        for (auto s : mp) {
            ans.push_back(s.second);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = sol.groupAnagrams(input);

    cout << "Grouped Anagrams:\n";
    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}
