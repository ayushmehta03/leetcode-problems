#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) 
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for(int i = 0; i < n; i++) {
        if(i > 0 && arr[i] == arr[i - 1]) continue; // skip duplicates for i

        int j = i + 1;
        int k = n - 1;

        while(j < k) {
            int sum = arr[i] + arr[j] + arr[k];

            if(sum < 0) {
                j++;
            } 
            else if(sum > 0) {
                k--;
            } 
            else {
                // Found a triplet
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;

                // Skip duplicates for j and k
                while(j < k && arr[j] == arr[j - 1]) j++;
                while(j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }

    // Output the result
    for(auto triplet : ans) {
        for(auto num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}