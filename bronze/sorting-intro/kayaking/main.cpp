#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int people[2 * N];
    for (int i = 0; i < 2 * N; i++) cin >> people[i];

    sort(people, people + 2 * N);

    // for (auto p : people)
    //     cout << p << " ";
    // cout << "\n";

    int min_instability = INT_MAX;
    int cur_instability = 0;

    // case 1: cut two people from either side
    for (int i = 1; i < 2 * N - 1; i += 2)
        cur_instability += abs(people[i] - people[i + 1]);

    min_instability = min(cur_instability, min_instability);
    // cout << "min instability: " << min_instability << "\n";

    // case 2: cut two consecutive people
    cur_instability = 0;
    int max_diff = 0;
    int cur_diff; // will be initialized
    for (int i = 0; i < 2 * N; i += 2) {
        cur_diff = abs(people[i] - people[i + 1]);
        max_diff = max(cur_diff, max_diff);
        cur_instability += cur_diff;
    }
    // cout << "max diff: " << max_diff << "\n";
    // cout << "cur instability: " << cur_instability << "\n";

    min_instability = min(cur_instability - max_diff, min_instability);

    cout << min_instability;
}
