// USACO 2019 December Contest, Bronze
// Problem 2. Where Am I?

#include <fstream>
#include <set>

using namespace std;

int main() {
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");

    int N;
    fin >> N;

    string mailboxes;
    fin >> mailboxes;

    for (int ws = 1; ws <= N; ws++) { // ws = window size
        set<string> windows;
        bool dup = false;
        for (int j = 0; j <= N - ws; j++) {
            if (windows.find(mailboxes.substr(j, ws)) != windows.end()) {
                dup = true;
                break;
            } else windows.insert(mailboxes.substr(j, ws));
        }

        // if this window has no duplicates at all, this is the answer
        if (!dup) {
            fout << ws << endl;
            break;
        }
    }

    return 0;
}

// int main() {
//     ifstream fin("whereami.in");
//     // ofstream fout("whereami.out");

//     int N;
//     fin >> N;

//     string mailboxes;
//     fin >> mailboxes;

//     set<string> s;
//     set<string> tmp;
//     int window_size = 0;

//     while (!s.empty() /* || got to the end */) {
//         for (int i = 0; i < mailboxes.size() - window_size; i++) {
//             if (s.find(mailboxes.substr(i, window_size)) != s.end()) {
//                 tmp.insert(mailboxes.substr(i, window_size));
//             }
//         }

//         s = tmp;
//         tmp.clear();
//     }
// }
