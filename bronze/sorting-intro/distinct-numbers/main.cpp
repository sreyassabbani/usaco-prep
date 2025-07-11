#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << 0;
        return 0;
    }

    int arr[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int num_distinct = 1;
    int prev = arr[0];

    for (int i = 1; i < N; i++) {
        if (prev != arr[i])
            ++num_distinct;
        prev = arr[i];
    }

    cout << num_distinct;
}
