#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);  // (duration, deadline)
    for (int i = 0; i < n; ++i) {
        cin >> tasks[i].first >> tasks[i].second;
    }

    // Sort by duration (ascending)
    sort(tasks.begin(), tasks.end());

    long long time = 0;
    long long total_reward = 0;

    for (auto &[a, d] : tasks) {
        time += a;
        total_reward += (d - time);
    }

    cout << total_reward << "\n";
    return 0;
}
