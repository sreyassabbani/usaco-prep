// USACO 2016 US Open Contest, Bronze
// Problem 1. Diamond Collector

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

    for (int i = 0; i < N; ++i) {
        fin >> diamonds[i];
    }

    sort(diamonds.begin(), diamonds.end());

    int max_d = 0; // max display-able
    int cur_d = 0; // cur display-able

    for (int i = 0; i < N; ++i) {
        cur_d = 0;
        for (int j = i; j < N; ++j) {
            if (diamonds[j] - diamonds[i] <= K) {
                ++cur_d;
            } else break;
        }
        max_d = max(max_d, cur_d);
    }

    fout << max_d;
}
