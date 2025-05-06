#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        if (target < 0) {
            target = -target;
        }

        int step = 0;
        int sum = 0;

        while (true) {
            step++;
            sum += step;
            if (sum == target) {
                return step;
            } else if (sum > target && (sum - target) % 2 == 0) {
                return step;
            }
        }
    }
};

int main() {
    Solution sol;
    int target;

    cout << "Enter the target: ";
    cin >> target;

    int result = sol.reachNumber(target);
    cout << "Minimum number of steps to reach " << target << " is: " << result << endl;

    return 0;
}

