// Codeforces Gym 102951 A

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> xs(N);
    vector<int> ys(N);
    for (int& x : xs) cin >> x;

    for (int& y : ys) cin >> y;

    int max_distance = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            max_distance =
                max(int(pow(xs[i] - xs[j], 2) + pow(ys[i] - ys[j], 2)),
                    max_distance);
        }
    }

    cout << max_distance;

    return 0;
}
