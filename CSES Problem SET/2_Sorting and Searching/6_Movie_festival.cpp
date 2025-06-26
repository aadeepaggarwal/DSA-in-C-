#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> movies(n);
    for (int i = 0; i < n; ++i) {
        cin >> movies[i].first >> movies[i].second;
    }

    // Sort movies by ending time
    sort(movies.begin(), movies.end(), [](pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
    });

    int count = 0, last_end = 0;

    for (auto movie : movies) {
        if (movie.first >= last_end) {
            count++;
            last_end = movie.second;
        }
    }

    cout << count << '\n';
    return 0;
}
