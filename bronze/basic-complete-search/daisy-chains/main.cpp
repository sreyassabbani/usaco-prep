// USACO 2020 December Contest, Bronze
// Problem 2. Daisy Chains

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> flowers(N);

    for (int& flower : flowers) cin >> flower;

    int num_avg_fl = N; // every (i, i) range counts

    if (N < 3) {
        cout << num_avg_fl;
        return 0;
    }

    for (int i = 0; i < N - 1; ++i) {
        for (int j = i + 1; j < N; ++j) { // skip (i, i) ranges
            int avg = 0;

            for (int f = i; f <= j; f++) avg += flowers[f];

            if (avg % (j - i + 1) != 0) // skip non-integer averages
                continue;

            avg /= j - i + 1;

            // search for avg
            for (int k = i; k <= j; ++k) {
                if (flowers[k] == avg) {
                    num_avg_fl++;
                    break;
                }
            }
        }
    }
    cout << num_avg_fl;

    return 0;
}
