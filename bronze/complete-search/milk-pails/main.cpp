// 2016 February Contest, Bronze
// Problem 1. Milk Pails

#include <fstream>
using namespace std;

int main() {
    ifstream fin("pails.in");
    ofstream fout("pails.out");

    int X, Y, M;
    fin >> X >> Y >> M;

    int closest = min(M - X, M - Y); // represents diff

    int current = X;
    while (current < M) {
        int i = 0;
        while (current <= M - Y) {
            current += Y;
            ++i;
        }
        closest = min(closest, M - current);
        current -= Y * i;
        current += X;
    }

    fout << M - closest;

    return 0;
}
