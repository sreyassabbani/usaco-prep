// 2019 February Contest, Bronze
// Problem 3. Measuring Traffic

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

constexpr int MIN = numeric_limits<int>::min();
constexpr int MAX = numeric_limits<int>::max();

pair<int, int> satisfy(pair<int, int>& a, pair<int, int>& b) {
    return pair(max(a.first, b.first), min(a.second, b.second));
}

int main() {
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int N; // number of mile segments
    cin >> N;

    // unset
    pair<int, int> in_record(MIN, MAX);
    pair<int, int> cur_record(MIN, MAX);
    pair<int, int> ext_flow(0, 0);       // resets after hitting `none`
    pair<int, int> ext_flow_start(0, 0); // persistent counter

    for (int i = 0; i < N; i++) {
        string type; // type of measurement
        cin >> type;

        int low, high;
        cin >> low >> high;

        if (type == "on") {
            ext_flow.first += low;
            ext_flow.second += high;
            ext_flow_start.first += low;
            ext_flow_start.second += high;

        } else if (type == "off") {
            ext_flow.first -= high;
            ext_flow.second -= low;
            ext_flow_start.first -= high;
            ext_flow_start.second -= low;

        } else if (type == "none") {
            pair<int, int> tmp_in(low - ext_flow_start.second,
                                  high - ext_flow_start.first);

            pair<int, int> tmp_cur(low, high);

            in_record = satisfy(tmp_in, in_record);
            cur_record = satisfy(tmp_cur, cur_record);

            // reset
            ext_flow = { 0, 0 };
        }
    }

    int after_min = cur_record.first + ext_flow.first;
    int after_max = cur_record.second + ext_flow.second;

    cout << in_record.first << " " << in_record.second << "\n";
    cout << after_min << " " << after_max << "\n";

    return 0;
}
