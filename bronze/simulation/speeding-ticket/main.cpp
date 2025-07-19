// 2015 December Contest, Bronze
// Problem 2. Speeding Ticket

#include <cstdio>
#include <iostream>
using namespace std;

// I had to peek at the solutions because I didn't read that the entire road is
// 100 units long and didn't consider just making an entry at every unit of
// every segment.
#define LEN 100

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int N; // number of road segments
    int M; // number of segments in Bessie's journey

    cin >> N;
    cin >> M;

    int limit[LEN] = { 0 };
    int bessie[LEN] = { 0 };

    // Initialize
    int cur_loc = 0;
    for (int i = 0; i < N; i++) {
        int road_segment_length;
        cin >> road_segment_length;

        // fill in the same limit for the entire road segment
        int lim;
        cin >> lim;
        for (int j = cur_loc; j < cur_loc + road_segment_length; j++)
            limit[j] = lim;

        cur_loc += road_segment_length;
    }

    cur_loc = 0;
    for (int i = 0; i < M; i++) {
        int drive_segment_length;
        cin >> drive_segment_length;

        // fill in the same speed for the entire road segment
        int speed;
        cin >> speed;
        for (int j = cur_loc; j < cur_loc + drive_segment_length; j++)
            bessie[j] = speed;

        cur_loc += drive_segment_length;
    }

    int over_limit = 0; // by how much is Bessie over limit?
    for (int i = 0; i < LEN; i++) {
        over_limit = max(bessie[i] - limit[i], over_limit);
    }

    cout << over_limit;
    return 0;
}
