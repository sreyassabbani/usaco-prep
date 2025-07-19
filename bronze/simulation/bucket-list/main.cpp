// 2018 December Contest, Bronze
// Problem 2. The Bucket List

#include <algorithm>
#include <array>
#include <climits>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ofstream fout("blist.out");
    ifstream fin("blist.in");

    int N;
    fin >> N;

    vector<array<int, 3>>
        cows; // start times, end times, buckets required for each

    int min_time = INT_MAX;
    int max_time = 0;

    // load input
    for (int i = 0; i < N; ++i) {
        int start;
        fin >> start;
        int end;
        fin >> end;
        int buckets;
        fin >> buckets;

        // would `emplace_back` have been a better choice?
        cows.push_back({ start, end, buckets });

        // update min and max
        min_time = min(start, min_time);
        max_time = max(end, max_time);
    }

    // use min and max to make a "timeline"
    vector<int> timeline(max_time - min_time + 1, 0);

    for (auto cow : cows) {
        for (int i = cow[0]; i <= cow[1]; ++i) {
            timeline[i - min_time] += cow[2];
        }
    }

    int max_buckets = 0;
    for (int i = 0; i < max_time - min_time + 1; ++i) {
        max_buckets = max(timeline[i], max_buckets);
    }

    fout << max_buckets;

    return 0;
}
