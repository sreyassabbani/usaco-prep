// 2016 December Contest, Bronze
// Problem 3. The Cow-Signal

#include <fstream>
using namespace std;

int main() {
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");

    int M, N, K;
    fin >> M >> N >> K;

    char signal[M * N];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            fin >> signal[i + j * M];
        }
    }

    for (int i = 0; i < M * K; i++) {
        for (int j = 0; j < N * K; j++) {
            fout << signal[(i / K) + (j / K) * M];
        }
        fout << "\n";
    }

    return 0;
}
