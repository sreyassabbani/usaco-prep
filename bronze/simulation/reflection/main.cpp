// USACO 2025 February Contest, Bronze
// Problem 1. Reflection

#include <iostream>
#include <vector>
using namespace std;

// r, c
// r, N - c - 1
// N - r - 1, c
// N - r - 1, N - c - 1

void update(vector<vector<char>>& canvas, int r, int c) {
    canvas[r][c] = (canvas[r][c] == '.' ? '#' : '.');
}

// calculates how many operations left to satisfy the reflective condition
int calc(vector<vector<char>>& canvas, int N) {
    int count = 0;
    for (int r = 0; r < N / 2; ++r)
        for (int c = 0; c < N / 2; ++c) {
            // clang-format off
            int dots = (canvas[r][c] == '.')
                     + (canvas[r][N - c - 1] == '.')
                     + (canvas[N - r - 1][c] == '.')
                     + (canvas[N - r - 1][N - c - 1] == '.');

            count += min(dots, 4 - dots);
        }
    return count;
}

int main() {
    int N, U;
    cin >> N >> U;

    vector<vector<char>> canvas(N, vector<char>(N));

    for (auto& row : canvas)
        for (auto& c : row) cin >> c;

    vector<pair<int, int>> updates(U);

    for (auto& [r, c] : updates) cin >> r >> c, --r, --c;

    cout << calc(canvas, N) << "\n";
    for (auto& [r, c] : updates) {
        update(canvas, r, c);
        cout << calc(canvas, N) << "\n";
    }

    return 0;
}
