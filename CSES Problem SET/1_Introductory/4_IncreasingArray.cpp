#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    long long moves = 0; // Changed to long long

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i > 0 && arr[i] < arr[i - 1]) {
            moves += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }

    cout << moves << endl;
    return 0;
}
