#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        return (s + s).find(goal) != string::npos;
    }
};

int main() {
    Solution sol;

    string s, goal;
    cout << "Enter original string: ";
    cin >> s;

    cout << "Enter goal string: ";
    cin >> goal;

    if (sol.rotateString(s, goal))
        cout << "Yes, it's a rotation.\n";
    else
        cout << "No, it's not a rotation.\n";

    return 0;
}
