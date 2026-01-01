// USACO 2018 February Contest, Bronze
// Problem 2. Hoofball

// Key observation:
//
// Every cow's next pass is uniquely determined. You can run simulation and mark
// visited easily without worrying about graph searchs.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector<int> simulate(vector<int>& sources, vector<int>& next) {
    int N = next.size();
    vector<bool> visited(N, false);
    vector<int> current;

    for (int& s : sources) visited[s] = true, current.push_back(s);

    for (int _i = 0; _i < N; _i++) {
        vector<int> tmp;
        for (int& c : current) {
            visited[next[c]] = true;
            tmp.push_back(next[c]);
        }

        current = std::move(tmp);
    }

    vector<int> falses;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) falses.push_back(i);
    }

    return falses;
}

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

    // forced sources: indeg == 0 nodes are unreachable otherwise.
    vector<int> sources;
    for (int i = 0; i < N; i++) {
        if (indeg[i] == 0) sources.push_back(i);
    }

    vector<int> unvisited = simulate(sources, next);
    while (!unvisited.empty()) {
        // you can't just add any unvisited node as a source.
        sort(unvisited.begin(), unvisited.end(),
             [&](int a, int b) { return indeg[a] > indeg[b]; });
        sources.push_back(unvisited[0]);
        unvisited = simulate(sources, next);
    }

    fout << sources.size();

    return 0;
}
