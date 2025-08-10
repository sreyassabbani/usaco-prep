// USACO 2020 February Contest, Bronze
// Problem 1. Triangles

// Take away:
//
// - O(N^3) is fine sometimes

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");

    int N;
    fin >> N;

    vector<pair<int, int>> pts(N);
    for (auto& pt : pts) fin >> pt.first >> pt.second;

    int max_area = 0;

    for (auto& [x1, y1] : pts) {
        for (auto& [x2, y2] : pts) {
            for (auto& [x3, y3] : pts) {
                int cur_area;
                if (x1 == x2 && y2 == y3) {
                    cur_area = abs(y2 - y1) * abs(x2 - x3);
                    max_area = max(cur_area, max_area);
                }
            }
        }
    }

    fout << max_area;
    return 0;
}
