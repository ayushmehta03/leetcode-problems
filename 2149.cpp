// Rearrange Array Element by Sign


#include <bits/stdc++.h>
using namespace std;

int main() {
    // Input
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result[n];
    int negativeIndex = 1, positiveIndex = 0;

    for(int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            result[negativeIndex] = arr[i];
            negativeIndex += 2;
        } else {
            result[positiveIndex] = arr[i];
            positiveIndex += 2;
        }
    }

    for(int i = 0; i < n; i++) {
        arr[i] = result[i];
    }

    cout << "The elements after rearrange are: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
