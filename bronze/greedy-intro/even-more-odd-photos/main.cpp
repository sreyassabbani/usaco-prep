#include <iostream>
using namespace std;

enum State { Odd, Even };

void sw(State& s) { s = (s == Even) ? Odd : Even; }

int main() {
    // how many # odd, even, total
    int N_O = 0, N_E = 0, N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int _tmp;
        cin >> _tmp;

        if (_tmp % 2 == 0) N_E++;
        else N_O++;
    }

    int res = 0;
    State s = Even;
    while (N_O > 0 || N_E > 0) {
        if (s == Even) {
            if (N_E > 0) {
                res++, sw(s);
                N_E--;
            } else if (N_O > 1) {
                res++, sw(s);
                N_O -= 2;
            } else {
                break;
            }
        } else /* if (s == Odd) */ {
            if (N_O > 0) res++, sw(s), N_O--;
            else break;
        }
    }

    // if there is a leftover odd
    if (N_O > 0) {
        // throw it with another odd to merge with an existing even
        /* if (res > 1) */ res--;
    }

    cout << res;
}
