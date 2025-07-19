// USACO 2022 US Open Contest, Bronze
// Problem 2. Counting Liars

// What to learn from this:
//
// - Leverage discrete values when you can (e.g. number lines in this problem or
// the ones in the highway speeding ticket problem)
//
// - Optimize around those discrete values (so here, check only p-1, p, and p+1
// instead of min..max)

#include <climits>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N;

    cin >> N;
    vector<pair<char, int>> all_stmts(N);
    vector<int> pts;

    for (pair<char, int>& stmt : all_stmts) {
        char c;
        int pt;
        cin >> c >> pt;

        stmt = {c, pt};

        pts.push_back(pt);
        pts.push_back(pt - 1);
        pts.push_back(pt + 1);
    }

    // find final answer
    int min_lying = INT_MAX;
    for (int& x : pts) {
        int cur_num_liers = 0;
        for (auto& [c, p] : all_stmts) {
            if (c == 'L') {
                if (x > p)
                    cur_num_liers++;
            } else /* c == 'G' */ {
                if (x < p)
                    cur_num_liers++;
            }
        }
        min_lying = min(min_lying, cur_num_liers);
    }

    cout << min_lying;

    return 0;
}
