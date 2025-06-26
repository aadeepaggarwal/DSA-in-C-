#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int len, q; cin >> len >> q;
    multiset<int> lens;
    lens.insert(len);

    set<pair<int, int>> ranges; // stores {start, end}
    ranges.insert({0, len});

    while (q--) {
        int x; cin >> x;
        auto it = ranges.upper_bound({x, INT_MAX});
        --it;

        int start = it->first;
        int end = it->second;
        int segment_len = end - start;

        ranges.erase(it);
        ranges.insert({start, x});
        ranges.insert({x, end});

        lens.erase(lens.find(segment_len));
        lens.insert(x - start);
        lens.insert(end - x);

        cout << *lens.rbegin() << " ";
    }

    return 0;
}
