// USACO 2020 February Contest, Bronze
// Problem 3. Swapity Swap

#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("swap.in");
    ofstream fout("swap.out");

    int N, K;
    fin >> N >> K;

    vector<int> cows(N);
    for (int i = 0; i < N; i++) cows[i] = i + 1;

    int A1, A2;
    fin >> A1 >> A2;
    A1--;

    int B1, B2;
    fin >> B1 >> B2;
    B1--;

    for (int k = 0; k < K; k++) {
        // A
        reverse(cows.begin() + A1, cows.begin() + A2);

        // B
        reverse(cows.begin() + B1, cows.begin() + B2);
    }

    for (int& c : cows) fout << c << "\n";
}
