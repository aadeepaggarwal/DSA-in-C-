#include <bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> store;

    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        store.push_back({start, 0}); // 0 means arrival/start
        store.push_back({end, 1});   // 1 means departure/end
    }

    sort(store.begin(), store.end(), comparator);

    int ans = 0, curr = 0;
    for (auto it : store) {
        if (it.second == 0) {
            curr++;
            ans = max(ans, curr);
        } else {
            curr--;
        }
    }

    cout << ans << '\n';
    return 0;
}
