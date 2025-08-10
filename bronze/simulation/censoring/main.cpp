// 2015 February Contest, Bronze
// Problem 1. Censoring

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    // I hoped I could get the last case to pass with premature optimization
    // (didn't happen)
    ifstream fin("censor.in");
    ofstream fout("censor.out");
    fin.tie(0)->sync_with_stdio(0);

    string text;
    fin >> text;
    auto p = text.begin();

    string censor;
    fin >> censor;

    int c_count = 0;
    int c_len = censor.size();

    while (p != text.end()) {
        if (c_count > 0 && *p == censor[c_count]) {
            c_count++;
            if (c_count == c_len) {
                // Erase and reset position
                auto erase_start = p - c_len + 1;
                auto erase_end = (c_len == 1) ? p + 1 : p + 1;
                p = text.erase(erase_start, erase_end);
                // Backtrack to check for new overlaps
                c_count = 0;
                if (p != text.begin())
                    p -= min(c_len, int(distance(text.begin(), p)));
                continue;
            }
        } else if (c_count > 0 && c_len == 1) {
            text.erase(p - 1, p);
        } else {
            c_count = (*p == censor[0]) ? 1 : 0;
        }
        p++;
    }

    fout << text;

    return 0;
}

// int pos = text.find(censor);
// while (pos != text.npos) {
//   text.erase(pos, censor.size());
//   pos = text.find(censor);
// }
