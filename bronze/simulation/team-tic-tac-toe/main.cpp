// 2018 US Open Contest, Bronze
// Problem 1. Team Tic Tac Toe

#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    char board[9];
    for (int i = 0; i < 9; i++)
        cin >> board[i];

    set<char> idvls;
    set<pair<char, char>> teams;

    auto add_team = [&](pair<char, char> team) mutable {
        if (teams.find(team) == teams.end()) { teams.insert(team); }
    };

    auto add_idvl = [&](char idvl) mutable {
        if (idvls.find(idvl) == idvls.end()) { idvls.insert(idvl); }
    };

    // check vertically
    for (int x = 0; x < 3; x++) {
        set<char> set;
        for (int y = 0; y < 3; y++) {
            set.insert(board[x + 3 * y]);
        }
        if (set.size() == 2) add_team(pair(*set.begin(), *++set.begin()));
        else if (set.size() == 1) add_idvl(*set.begin());
    }

    // check horizontally
    for (int y = 0; y < 3; y++) {
        set<char> set;
        for (int x = 0; x < 3; x++) {
            set.insert(board[x + 3 * y]);
        }
        if (set.size() == 2) add_team(pair(*set.begin(), *++set.begin()));
        else if (set.size() == 1) add_idvl(*set.begin());
    }

    // check diagonally (decreasing diagonal)
    set<char> dec_diag;
    for (int n = 0; n < 3; n++) {
        dec_diag.insert(board[4 * n]);
    }
    if (dec_diag.size() == 2)
        add_team(pair(*dec_diag.begin(), *++dec_diag.begin()));
    else if (dec_diag.size() == 1) add_idvl(*dec_diag.begin());

    // check diagonally (increasing diagonal)
    set<char> inc_diag;
    for (int n = 0; n < 3; n++) {
        inc_diag.insert(board[2 * n + 2]);
    }
    if (inc_diag.size() == 2)
        add_team(pair(*inc_diag.begin(), *++inc_diag.begin()));
    else if (inc_diag.size() == 1) add_idvl(*inc_diag.begin());

    cout << idvls.size() << "\n" << teams.size();
    return 0;
}
