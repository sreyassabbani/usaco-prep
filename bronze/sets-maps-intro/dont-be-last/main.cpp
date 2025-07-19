// USACO 2017 January Contest, Bronze
// Problem 1. Don't Be Last!

// Take-aways
//
// - You don't always need to sort. If you need to get Nth smallest number in an
// array (or some collection), you can just loop N times, and for N << length of
// array, it will be better than sorting. This is especially true if you want to
// work with maps or sets

#include <climits>
#include <fstream>
#include <iostream>
#include <map>
using namespace std;

int main() {
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");

    int N;
    fin >> N;

    map<string, int> record {
        { "Bessie",    0 },
        { "Elsie",     0 },
        { "Daisy",     0 },
        { "Gertie",    0 },
        { "Annabelle", 0 },
        { "Maggie",    0 },
        { "Henrietta", 0 }
    };

    for (int i = 0; i < N; i++) {
        string name;
        int amount;
        fin >> name >> amount;

        record[name] += amount;
    }

    int min_amount = INT_MAX;

    for (auto& [_, amount] : record) {
        min_amount = min(amount, min_amount);
    }

    int second_min_amount = INT_MAX;
    string cow_name;
    int second_count = 0;

    for (auto& [name, amount] : record) {
        if (amount != min_amount && amount <= second_min_amount) {
            if (amount < second_min_amount) {
                second_min_amount = amount;
                cow_name = name;
                second_count = 1;
            } else /* amount == second_min_amount */ {
                ++second_count;
            }
        }
    }

    if (second_min_amount == INT_MAX || second_count > 1) fout << "Tie";
    else fout << cow_name;

    fout << endl;

    return 0;
}
