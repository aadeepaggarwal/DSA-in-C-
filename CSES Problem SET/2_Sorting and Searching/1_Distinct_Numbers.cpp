#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    set<long long> freq;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        freq.insert(x);
    }
    cout << freq.size() << endl;
    return 0;
}
