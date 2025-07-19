// USACO 2016 US Open Contest, Bronze
// Problem 1. Diamond Collector

// This alternate solution doesn't sort the original `diamonds` vector so runs
// faster than my solution in `main.cpp`. Instead of sorting, we check on
// another condition `y > x` before updating `cur_d` and no longer break on else
//
// Instead of iterating `i` from 0..N, we just iterate (with reference) over the
// `diamonds` vector; this saves dev time

#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");

    int N, K;

    fin >> N >> K;

    vector<int> diamonds(N);

    // faster way?
    for (int& d : diamonds) {
        fin >> d;
    }

    // - for (int i = 0; i < N; ++i) {
    // -     fin >> diamonds[i];
    // - }

    // - sort(diamonds.begin(), diamonds.end());

    int max_d = 0; // max display-able

    for (int& x : diamonds) {
        int cur_d = 0; // cur display-able

        for (int& y : diamonds) {
            if (y - x <= K && y >= x) ++cur_d;
        }
        max_d = max(max_d, cur_d);
    }

    fout << max_d;
}
