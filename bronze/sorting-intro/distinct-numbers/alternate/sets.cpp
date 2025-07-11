// Interestingly, a variant of this solution with `unordered_map` instead of
// `map` does not run within the time limits of the last test case on CSES.
//
// Although insertion is O(1) amortized for hash-based sets (like
// `std::set`), its worst case has most likely been exploited somehow in the
// given CSES problem to reject any hash-based map solutions. If you insert `N`
// objects, each having O(M) insertion (if you let M be the current size of the
// set), you will end with an overall O(N^2) runtime, worse than the `std::sort`
// O(N * log(N)).

#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    set<int> nums;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        nums.insert(tmp);
    }

    cout << nums.size();
}
