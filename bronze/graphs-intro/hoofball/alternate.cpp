// USACO 2018 February Contest, Bronze
// Problem 2. Hoofball

// Key observation:
//
// All cycles except 2-cycles cannot exist.
//
// A little bit more reasoning brings you to: only required sources are 2-cycles
// and 0-indegree cows

#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("hoofball.in");
    ofstream fout("hoofball.out");

    int N;
    fin >> N;

    vector<int> pos(N);
    for (int& p : pos) fin >> p;
    sort(pos.begin(), pos.end());

    // next[i] = index of cow that cow i passes to (next pass)
    vector<int> next(N);

    // ends have only one choice
    next[0] = 1;
    next[N - 1] = N - 2;

    for (int i = 1; i <= N - 2; i++) {
        int dL = pos[i] - pos[i - 1];
        int dR = pos[i + 1] - pos[i];
        if (dL <= dR) next[i] = i - 1;
        else next[i] = i + 1;
    }

    // indegree (how many can pass to i)
    vector<int> indeg(N, 0);
    for (int i = 0; i < N; i++) indeg[next[i]]++;

    int ans = 0;

    // forced sources: indeg == 0 nodes are unreachable otherwise.
    for (int i = 0; i < N; i++) {
        if (indeg[i] == 0) ans++;
    }

    // isolated 2-cycles are also forced sources
    for (int i = 0; i < N; i++) {
        int j = next[i];
        if (j > i && next[j] == i) {            // mutual pair counted once
            if (indeg[i] == 1 && indeg[j] == 1) // check mutual
                ans++;
        }
    }

    fout << ans;

    return 0;
}
