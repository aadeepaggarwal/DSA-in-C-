#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<array<int, 3>> events(n); 
    // events[i] = {end, start, value}

    for (auto &e : events) {
        cin >> e[1] >> e[0] >> e[2]; 
        // Reading: start, end, value -> stored as {end, start, value}
    }

    sort(events.begin(), events.end()); 
    // Sorting by end time (e[0])

    int res = 0;
    set<array<int, 2>> dp; 
    // Each element: {end time, max value till this end time}
    
    dp.insert({0, 0}); 
    // Base case: before any event, max value is 0

    for (auto &e : events) {
        auto lb = dp.lower_bound({e[1], 0}); 
        // Find first event in dp with end time >= current start time
        lb--;
        // Move to the last event that ends before current start

        res = max((*lb)[1] + e[2], res); 
        // Either take current event (add its value to dp of last compatible event) 
        // or keep previous max

        dp.insert({e[0], res}); 
        // Store new result with current event's end time
    }

    cout << res << endl;

    return 0;
}
