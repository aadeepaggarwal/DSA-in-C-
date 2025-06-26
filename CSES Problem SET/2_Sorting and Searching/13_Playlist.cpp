#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int p1 = 0, p2 = 0, ans = 0;
    set<int> tally;

    while(p1 < n) {
        if(tally.find(arr[p1]) == tally.end()) {
            tally.insert(arr[p1]);
            ans = max(ans, p1 - p2 + 1);
            p1++;
        } else {
            tally.erase(arr[p2]);
            p2++;
        }
    }

    cout << ans << endl;
    return 0;
}
