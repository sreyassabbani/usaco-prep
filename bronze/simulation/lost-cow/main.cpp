// 2017 US Open Contest, Bronze
// Problem 1. The Lost Cow

#include <fstream>
using namespace std;

int main() {
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");

    int start, y;
    fin >> start >> y;

    int x = start;

    int total = 0; // total distance traveled
    int i = 0;

    while ((y - start) * (y - x) >
           0) { // goofy way of checking for opposite signs
        int sign = (i % 2 == 0) ? 1 : -1;
        int next = start + sign * (1 << i); // bit shift

        int change = abs(x - next);

        x = next;

        i++;
        total += change;
    }
    if ((y - start) * (y - x) < 0) { total -= abs(x - y); }

    fout << total;
}
