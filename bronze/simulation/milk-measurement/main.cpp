// USACO 2017 December Contest, Bronze
// Problem 3. Milk Measurement

#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

void update(int (&arr)[100], int from_day, int amount) {
    for (int i = from_day; i < 100; ++i) {
        arr[i] += amount;
    }
}

int main() {
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int N;
    cin >> N;

    int elsie_days[100];
    int bessie_days[100];
    int mildred_days[100];

    // pointer arithmetic!!
    fill(elsie_days, elsie_days + 100, 7);
    fill(bessie_days, bessie_days + 100, 7);
    fill(mildred_days, mildred_days + 100, 7);

    for (int i = 1; i <= N; ++i) {
        int day;
        cin >> day;

        string name;
        cin >> name;

        int change;
        cin >> change;

        if (name == "Elsie") {
            update(elsie_days, day, change);
        } else if (name == "Bessie") {
            update(bessie_days, day, change);
        } else if (name == "Mildred") {
            update(mildred_days, day, change);
        }
    }

    int updates = 0;
    // "E" or "B" or "M" or "EM" or "EB" or "BM" or "A"
    string current = "A";
    string prev = current;
    // check every day for updates
    for (int i = 1; i < 100; ++i) {
        int E = elsie_days[i];
        int B = bessie_days[i];
        int M = mildred_days[i];
        if (E > B && E > M) {
            current = "E";
        } else if (B > E && B > M) {
            current = "B";
        } else if (M > E && M > B) {
            current = "M";
        } else if (M == E && M > B) {
            current = "EM";
        } else if (E == B && E > M) {
            current = "EB";
        } else if (B == M && B > E) {
            current = "BM";
        } else {
            current = "A";
        }
        if (current != prev) { updates++; }
        prev = current;
    }
    cout << updates;
}
