// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;

//     vector<int> tickets(n);
//     for (int i = 0; i < n; ++i) {
//         cin >> tickets[i];
//     }
//     sort(tickets.begin(), tickets.end());

//     for (int i = 0; i < m; ++i) {
//         int offer;
//         cin >> offer;

//         // upper_bound gives first ticket > offer
//         auto it = upper_bound(tickets.begin(), tickets.end(), offer);

//         if (it == tickets.begin()) {
//             cout << -1 << '\n';
//         } else {
//             --it;  // get ticket <= offer
//             cout << *it << '\n';
//             tickets.erase(it);  // remove sold ticket
//         }
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<int, int> tickets;
    for (int i = 0; i < n; ++i) {
        int price;
        cin >> price;
        tickets[price]++;  // count frequency
    }

    for (int i = 0; i < m; ++i) {
        int offer;
        cin >> offer;

        // Find the largest ticket price <= offer
        auto it = tickets.upper_bound(offer);
        if (it == tickets.begin()) {
            cout << -1 << '\n';
        } else {
            --it;
            cout << it->first << '\n';
            if (--it->second == 0) {
                tickets.erase(it);  // remove if no tickets left at that price
            }
        }
    }

    return 0;
}
