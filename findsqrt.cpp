#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int low = 1;
        int high = x;
        int mid = -1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if ((long long)mid * mid > x)
                high = mid - 1;
            else if (mid * mid == x)
                return mid;
            else
                low = mid + 1;
        }
        return high; // No need to use round() here
    }
};

int main() {
    Solution sol;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    int result = sol.mySqrt(num);
    cout << "Square root (floor): " << result << endl;
    return 0;
}
