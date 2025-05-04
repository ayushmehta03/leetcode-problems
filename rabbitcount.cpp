#include <iostream>
#include <vector>
using namespace std;

int numRabbits(vector<int>& answers) {
    vector<int> count(1000, 0);
    int ans = 0;
    for (int x : answers) {
        count[x]++;
        if (count[x] == 1) {
            ans += x + 1;
        }
        if (count[x] == x + 1) {
            count[x] = 0;
        }
    }
    return ans;
}

int main() {
    vector<int> answers = {1, 1, 2};  // Example input
    cout << "Number of Rabbits: " << numRabbits(answers) << endl;
    return 0;
}
