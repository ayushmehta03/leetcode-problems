#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN, el2 = INT_MIN;

    // 1st pass to find potential candidates
    for(int i = 0; i < n; i++) {
        if(cnt1 == 0 && arr[i] != el2) {
            cnt1 = 1;
            el1 = arr[i];
        }
        else if(cnt2 == 0 && arr[i] != el1) {
            cnt2 = 1;
            el2 = arr[i];
        }
        else if(arr[i] == el1) cnt1++;
        else if(arr[i] == el2) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }

    // 2nd pass to validate counts
    cnt1 = cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == el1) cnt1++;
        else if(arr[i] == el2) cnt2++; // use else if to avoid double counting when el1 == el2
    }

    vector<int> ans;
    if(cnt1 > n / 3) ans.push_back(el1);
    if(cnt2 > n / 3 && el2 != el1) ans.push_back(el2);

    cout << "The majority elements are:" << endl;
    for(int num : ans) {
        cout << num << " ";
    }

    return 0;
}
