// USACO 2016 January Contest, Bronze
// Problem 3. Mowing the Field

#include <climits>
#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

void move(pair<int, int>& pos, char dir) {
    if (dir == 'N') {
        pos.second++;
    } else if (dir == 'S') {
        pos.second--;
    } else if (dir == 'E') {
        pos.first++;
    } else if (dir == 'W') {
        pos.first--;
    }
}

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int N;
    cin >> N;

    bool has_doubled = false;
    // for unordered_map, you have to provide a custom hash for pair<int, int>,
    // so I'm using map here.
    map<pair<int, int>, int> grid;

    pair<int, int> cur_pos{0, 0};
    int t = 0;

    int x_max = INT_MAX;

    grid.insert({cur_pos, 0});

    for (int i = 0; i < N; i++) {
        char dir;
        cin >> dir;

        int magnitude;
        cin >> magnitude;

        for (int j = 0; j < magnitude; j++) {
            t++;
            move(cur_pos, dir);
            if (grid.find(cur_pos) != grid.end()) {
                has_doubled = true;
                x_max = min(x_max, t - grid[cur_pos]);
            }
            grid[cur_pos] = t;
        }
    }

    if (has_doubled)
        cout << x_max;
    else
        cout << -1;
}
