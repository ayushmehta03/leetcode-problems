#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        vector<int> counter(26, 0); // For lowercase English letters only

        for (int i = 0; i < s.length(); i++) {
            counter[s[i] - 'a']++; // Increment count for s
            counter[t[i] - 'a']--; // Decrement count for t
        }

        for (int count : counter) {
            if (count != 0) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";

    if (sol.isAnagram(s, t)) {
        cout << "The strings are anagrams." << endl;
    } else {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
