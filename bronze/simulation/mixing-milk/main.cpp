// 2018 December Contest, Bronze
// Problem 1. Mixing Milk

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);

  int caps[3];
  int amts[3];

  cin >> caps[0]; 
  cin >> amts[0]; 

  cin >> caps[1]; 
  cin >> amts[1]; 

  cin >> caps[2]; 
  cin >> amts[2]; 

  for (int i = 0; i < 100; i++) {
    int from_bucket = i % 3;
    int to_bucket = (i + 1) % 3;
    int transfer_amount = min(caps[to_bucket] - amts[to_bucket], amts[from_bucket]); // transfer as much from `from_bucket` as possible

    amts[from_bucket] -= transfer_amount;
    amts[to_bucket] += transfer_amount;
  }

  cout << amts[0] << "\n" << amts[1] << "\n" << amts[2] << endl;

  return 0;
}
