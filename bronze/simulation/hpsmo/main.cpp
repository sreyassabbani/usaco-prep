// 2025 US Open, Bronze
// Problem 1. Hoof Paper Scissors Minus One

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  char convention[N * (N + 1) / 2];

  for (int i = 0; i < N * (N + 1) / 2; ++i) {
    char C; cin >> C;
    convention[i] = C;
  }


  for (int i = 0; i < M; ++i) {
    int A, B; cin >> A >> B;
    
    set<int> lA; // set of materials that A loses to
    set<int> lB; // set of materials that B loses to

    // check which materials A loses to
    for (int j = 1; j <= N; ++j) {
      if (j == A) continue;
      int mx = max(j, A);
      int mn = min(j, A);
      int index = mx * (mx + 1) / 2 - (mx - mn) - 1;
      if ((j < A && convention[index] == 'L') || j > A && convention[index] == 'W') {
        lA.insert(j);
      }
    }
    
    // check which materials B loses to
    for (int j = 1; j <= N; ++j) {
      if (j == B) continue;
      int mx = max(j, B);
      int mn = min(j, B);
      int index = mx * (mx + 1) / 2 - (mx - mn) - 1;
      if ((j < B && convention[index] == 'L') || j > B && convention[index] == 'W') {
        lB.insert(j);
      }
    }

    vector<int> intersection;
    set_intersection(lA.begin(), lA.end(), lB.begin(), lB.end(), back_inserter(intersection));
    int n = intersection.size();
    cout << 2 * N * n - n * n << "\n";
  }


  return 0;
}


