// USACO 2019 US Open Contest, Bronze
// Problem 2. Milk Factory

// Key observation:
//
// For N stations, there will always be N - 1 walkways. There will be one "sink"
// node if and only if there is *at most* one node with an out-degree of 0.
//
// Consider the input:
//
// ```
// 3
// 1 2
// 1 3
// ```
//
// Here, you can see how both vertices 2 and 3 have out-degrees of 0.
//
// Also note how requiring a station to have 0 out-degree for it must be
// visitable by every other station (indirectly) is neither a sufficient
// condition or even a necessary condition at all! Consider a simple cycle.

#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream fin("factory.in");
    ofstream fout("factory.out");

    int N;
    fin >> N;

    // out-degrees
    vector<int> odeg(N, 0);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        fin >> a, fin >> b;

        // a -> b
        odeg[a - 1]++;
    }

    int res = -1;
    int sinks = 0;

    for (int i = 0; i < N; i++) {
        if (odeg[i] == 0) {
            sinks++;
            res = i + 1;
        }
    }

    if (sinks > 1) fout << -1;
    else fout << res;
}
