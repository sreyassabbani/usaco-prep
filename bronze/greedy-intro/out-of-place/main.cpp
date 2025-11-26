// USACO 2018 January Contest, Bronze
// Problem 3. Out of Place

#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int main() {

    ifstream fin("outofplace.in");
    if (!fin) return 1;

    ofstream fout("outofplace.out");

    int N;
    fin >> N;

    vector<int> lineup(N);
    for (int& cow : lineup) { fin >> cow; }

    vector<int> sorted(lineup);
    sort(sorted.begin(), sorted.end());

    int swaps = 0;

    for (int i = 0; i < N; i++)
        if (sorted[i] != lineup[i]) swaps++;

    fout << (swaps > 1 ? swaps - 1 : 0) << "\n";

    return 0;
}
