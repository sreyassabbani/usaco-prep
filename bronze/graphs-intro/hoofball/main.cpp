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

void pr(const vector<int>& v) {
    for (const auto& x : v) cout << x << " ";
    cout << "\n";
}

void pr(const vector<pair<int, int>>& v) {
    for (const auto& [x, y] : v) cout << "(" << x << ", " << y << ") ";
    cout << "\n";
}

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

    // NOTE: now we don't consider the actual identity/location of the cows
    // 1 3 4 7 11 -> 0 1 2 3 4

    // next pass
    vector<int> next(N, 0);

    // odeg, i (not cow_pos)
    vector<pair<int, int>> ideg(N);
    for (int i = 0; i < N; i++) ideg[i].second = i;

    next[0] = 1, next[N - 1] = N - 2;
    ideg[1].first++;
    ideg[N - 2].first++;

    // figure out the rest
    for (int i = 1; i < N - 1; i++) {
        int before = pos[i - 1];
        int cur = pos[i];
        int after = pos[i + 1];

        if (cur - before > after - cur) next[i] = i + 1, ideg[i + 1].first++;
        else next[i] = i - 1, ideg[i - 1].first++;
    }
    cout << "ideg: " << endl;
    pr(ideg);

    sort(ideg.begin(), ideg.end());
    reverse(ideg.begin(), ideg.end());

    cout << "ideg: " << endl;
    pr(ideg);

    int res = 0;
    vector<int> sources;

    sources.push_back(ideg[0].second);

    vector<int> not_visited = simulate(sources, next);
    while (!not_visited.empty()) {

        sort(not_visited.begin(), not_visited.end(),
             [&](int a, int b) { return ideg[a].first > ideg[b].first; });

        cout << "sources: " << endl;
        pr(sources);
        cout << "not visited: " << endl;
        pr(not_visited);

        sources.push_back(not_visited.back());
        not_visited.pop_back();
        not_visited = simulate(sources, next);
    }

    cout << sources.size();

    return 0;
}

// int main() {
//     ifstream fin("hoofball.in");
//     ofstream fout("hoofball.out");

//     int N;
//     fin >> N;

//     vector<int> cow_pos(N);
//     for (int& pos : cow_pos) fin >> pos;

//     sort(cow_pos.begin(), cow_pos.end());

//     vector<int> odeg(N, 0);

//     // the first and last cows have no other option but to pass to the second
//     // and second to last cows, respectively
//     odeg[1] = 1, odeg[N - 2] = 1;

//     // figure out the rest
//     for (int i = 1; i < N - 1; i++) {
//         int before = cow_pos[i - 1];
//         int cur = cow_pos[i];
//         int after = cow_pos[i + 1];

//         if (cur - before > after - cur) odeg[i + 1]++;
//         else odeg[i - 1]++;
//     }

//     int res = 0;
//     for (int i = 0; i < N; i++)
//         if (odeg[i] == 0) res++;

//     fout << res;

//     return 0;
// }
