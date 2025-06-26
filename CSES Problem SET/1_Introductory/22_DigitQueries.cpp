#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int main() {
    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;

        ll digit_len = 1;
        ll count = 9;
        ll start = 1;

        // Step 1: Determine the block where the k-th digit lies
        while (k > digit_len * count) {
            k -= digit_len * count;
            digit_len++;
            count *= 10;
            start *= 10;
        }

        // Step 2: Find the actual number containing the k-th digit
        ll number_index = (k - 1) / digit_len;
        ll number = start + number_index;

        // Step 3: Get the digit from the number
        string s = to_string(number);
        cout << s[(k - 1) % digit_len] << endl;
    }
    return 0;
}
