// USACO 2017 January Contest, Bronze
// Problem 3. Cow Tipping

#include <fstream>
#include <string>
#include <vector>
using namespace std;

void flip(vector<vector<bool>>& grid, int i, int j) {
    for (int x = 0; x <= i; ++x)
        for (int y = 0; y <= j; ++y) grid[x][y] = 1 - grid[x][y];
}

int main() {
    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");

    int N;
    fin >> N;

    vector<vector<bool>> grid(N, vector<bool>(N));
    for (int i = 0; i < N; ++i) {
        string s;
        fin >> s;
        for (int j = 0; j < N; ++j) grid[i][j] = s[j] == '1';
    }

    int flips = 0;

    for (int i = N - 1; i >= 0; --i) {
        for (int j = N - 1; j >= 0; --j) {
            if (grid[i][j] == 1) {
                flip(grid, i, j);
                ++flips;
            }
        }
    }

    fout << flips << "\n";
    return 0;
}
