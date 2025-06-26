#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<long long> set1, set2;
    long long target = sum / 2;
    for (long long i = n; i >= 1; --i) {
        if (target >= i) {
            set1.push_back(i);
            target -= i;
        } else {
            set2.push_back(i);
        }
    }
    cout << set1.size() << "\n";
    for (auto x : set1) cout << x << " ";
    cout << "\n" << set2.size() << "\n";
    for (auto x : set2) cout << x << " ";
    cout << "\n";
    return 0;
}