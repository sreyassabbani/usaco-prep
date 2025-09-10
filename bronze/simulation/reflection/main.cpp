// USACO 2025 February Contest, Bronze
// Problem 1. Reflection

#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// r, c
// r, N - c - 1
// N - r - 1, c
// N - r - 1, N - c - 1

int main() {
    int N, U;
    cin >> N >> U;

    vector<vector<char>> canvas(N, vector<char>(N));

    function<int(int, int)> calc = [&](int r, int c) {
        // clang-format off
        return (canvas[r][c] == '.')
             + (canvas[r][N - c - 1] == '.')
             + (canvas[N - r - 1][c] == '.')
             + (canvas[N - r - 1][N - c - 1] == '.');
    };

    for (auto& row : canvas)
        for (auto& c : row) cin >> c;

    vector<pair<int, int>> updates(U);

    for (auto& [r, c] : updates) cin >> r >> c, --r, --c;

    int count = 0;
    for (int r = 0; r < N / 2; ++r)
        for (int c = 0; c < N / 2; ++c) {
            int dots = calc(r, c);

            count += min(dots, 4 - dots);
        }

    cout << count << "\n";

    for (auto& [r, c] : updates) {
        int prev_dots = calc(r, c);

        canvas[r][c] = (canvas[r][c] == '.' ? '#' : '.');

        int cur_dots = calc(r, c);

        count += min(cur_dots, 4 - cur_dots) - min(prev_dots, 4 - prev_dots);
        cout << count << "\n";
    }

    return 0;
}
