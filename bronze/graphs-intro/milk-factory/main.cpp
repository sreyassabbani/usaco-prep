// USACO 2019 US Open Contest, Bronze
// Problem 2. Milk Factory

#include <algorithm>
#include <fstream>
#include <functional>
#include <vector>

using namespace std;

int main() {
    ifstream fin("factory.in");
    ofstream fout("factory.out");

    int N;
    fin >> N;

    vector<vector<int>> adj(N, vector<int>());

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        fin >> a, fin >> b;

        // a -> b
        adj[b - 1].push_back(a - 1);
    }

    int res = -1;

    function<void(int, vector<bool>&)> dfs = [&](int u, vector<bool>& visited) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) dfs(v, visited);
        }
    };

    for (int i = 0; i < N; i++) {
        // cout << "i: " << i << endl;
        // for (int& a : adj[i]) cout << a << " ";
        // cout << endl;

        // see if you can get from adj[i] to everything
        if (adj[i].size() == N - 1) {
            if (res >= 0) res = min(res, i + 1);
            else res = i + 1;
            break;
        }

        vector<bool> visited(N, false);
        for (int& j : adj[i]) dfs(j, visited);

        bool all_marked = true;
        for (int j = 0; j < N; j++) {
            if (i != j) all_marked &= visited[j];
        }

        if (all_marked) {
            if (res >= 0) res = min(res, i + 1);
            else res = i + 1;
        }
    };

    fout << res;
}
