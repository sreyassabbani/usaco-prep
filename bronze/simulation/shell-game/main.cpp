// 2019 January Contest, Bronze
// Problem 1. Shell Game

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    // current state of shells
    vector<int> state = { 1, 2, 3 };

    // theoretical score if the pebble was under n-th shell (3 shells)
    // {0, 0, 0}
    vector<int> assume(3, 0);

    // number of swaps (number of lines)
    int S;
    cin >> S;

    for (int i = 0; i < S; i++) {
        int a, b, g;
        cin >> a >> b >> g;

        // 0-indexed
        --a;
        --b;
        --g;

        // swap
        int tmp = state[a];
        state[a] = state[b];
        state[b] = tmp;

        assume[state[g] - 1]++;
    }

    int high = 0;
    for (int i : assume) high = max(high, i);
    cout << high;

    return 0;
}
