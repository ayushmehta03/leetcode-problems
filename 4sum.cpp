#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (j != i + 1 && arr[j] == arr[j - 1]) continue;

            int k = j + 1, l = n - 1;
            while (k < l) {
                long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];
                if (sum == target) {
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;
                    while (k < l && arr[k] == arr[k - 1]) k++;
                    while (k < l && arr[l] == arr[l + 1]) l--;
                } else if (sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }

    cout << "\nQuadruplets that sum to " << target << ":\n";
    if (ans.empty()) {
        cout << "No such quadruplets found.\n";
    } else {
        for (const auto& quad : ans) {
            for (int num : quad) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
