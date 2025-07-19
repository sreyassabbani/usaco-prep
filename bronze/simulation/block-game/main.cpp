// 2016 December Contest, Bronze
// Problem 2. Block Game

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int N;
    cin >> N;

    string front[N];
    string back[N];
    for (int i = 0; i < N; i++) {
        cin >> front[i];
        cin >> back[i];
    }

    int min_blocks[26] { 0 }; // min blocks of each letter in alphabet

    for (int i = 0; i < N; i++) {
        int min_blocks_front[26] { 0 }; // min blocks of each letter in alphabet
        for (char ch : front[i]) {
            min_blocks_front[int(ch) - 97] += 1; // defaults 0
        }

        int min_blocks_back[26] { 0 }; // min blocks of each letter in alphabet
        for (char ch : back[i]) {
            min_blocks_back[int(ch) - 97] += 1;
        }

        for (int j = 0; j < 26; j++) {
            min_blocks[j] += max(min_blocks_back[j], min_blocks_front[j]);
        }
    }
    for (int i = 0; i < 26; i++)
        cout << min_blocks[i] << "\n";

    return 0;
}
