// USACO 2022 December Contest, Bronze
// Problem 1. Cow College

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> pay(N);

    for (long long& p : pay) cin >> p;

    sort(pay.begin(), pay.end());

    int max_i = 0;

    for (int i = 0; i < N; ++i)
        if (pay[i] * (N - i) > pay[max_i] * (N - max_i)) max_i = i;

    cout << pay[max_i] * (N - max_i) << " " << pay[max_i];

    return 0;
}
