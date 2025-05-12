#include <iostream>
#include <vector>
#include <cmath>    // For ceil
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& dist, int speed, double hour) {
        double ans = 0;
        for (int i = 0; i < dist.size(); i++) {
            double d = static_cast<double>(dist[i]) / speed;
            if (i != dist.size() - 1)
                ans += ceil(d);
            else
                ans += d;
            if (ans > hour) return false;
        }
        return ans <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int i = 1;
        int j = 1e7;
        int minSpeed = -1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (isPossible(dist, mid, hour)) {
                minSpeed = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return minSpeed;
    }
};

int main() {
    Solution sol;
    vector<int> dist = {1, 3, 2};
    double hour = 6.0;

    int result = sol.minSpeedOnTime(dist, hour);
    cout << "Minimum speed: " << result << endl;

    return 0;
}
