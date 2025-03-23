// 2016 February Contest, Bronze
// Problem 2. Circular Barn 

#include <climits>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
  ifstream fin("cbarn.in");
  ofstream fout("cbarn.out");
  
  int N; fin >> N;
  int circle[N];
  for (int i = 0; i < N; ++i) fin >> circle[i];

  int min_total = INT_MAX;
  for (int i = 0; i < N; ++i) {
    int total = 0;
    for (int j = 0; j < N; ++j) {
      total += j * circle[(j + i) % N];
    }
    min_total = min(total, min_total);
  }
  
  fout << min_total;
  
  return 0;
}
