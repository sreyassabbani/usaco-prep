// 2017 December Contest, Bronze
// Problem 2. The Bovine Shuffle

#include <fstream>
using namespace std;

int main() {
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");

    int N; // number of cows
    fin >> N;

    int a[N]; // shuffle pattern
    for (int i = 0; i < N; ++i) fin >> a[i];

    int ids[N];
    for (int i = 0; i < N; ++i) fin >> ids[i];

    int cur[N]; // current ordering
    for (int i = 0; i < N; ++i) cur[i] = i + 1;
    int next[N]; // next ordering

    for (int i = 0; i < 3; ++i) { // "antishuffle" 3 times
        for (int j = 0; j < N; ++j) {
            // forward shuffle: next[a[j]-1] = cur[j]
            // reverse shuffle: next[j] = cur[a[j]-1]

            next[j] = cur[a[j] - 1];
        }

        copy(next, next + N, cur);
    }

    for (int i = 0; i < N; ++i) fout << ids[cur[i] - 1] << "\n";

    return 0;
}
