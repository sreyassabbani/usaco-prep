// USACO 2017 February Contest, Bronze
// Problem 3. Why Did the Cow Cross the Road III

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");

    int N;
    fin >> N;

    vector<pair<int, int>> times(N);
    for (auto& [a, b] : times) fin >> a >> b;

    sort(times.begin(), times.end());

    int cur = times[0].first;

    for (auto& [arrival, duration] : times) {
        if (cur < arrival) cur = arrival;
        cur += duration;
    }

    fout << cur;
}
