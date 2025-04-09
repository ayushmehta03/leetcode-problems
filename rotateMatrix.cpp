#include <bits/stdc++.h>
using namespace std;

int main() {
    int rows, columns;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> columns;

    if (rows != columns) {
        cout << "Error: In-place transpose is only possible for square matrices!" << endl;
        return 0;
    }

    vector<vector<int>> arr(rows, vector<int>(columns));

    cout << "Enter elements for the matrix:" << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cin >> arr[i][j];

    // Transpose
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < columns; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    for (int i = 0; i < rows; i++) {
        reverse(arr[i].begin(), arr[i].end());
    }

    //
    cout << "The mirror image of the matrix is:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
