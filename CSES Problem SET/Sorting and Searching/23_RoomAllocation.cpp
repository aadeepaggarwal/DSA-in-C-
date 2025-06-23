#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<tuple<int, int, int>> customers(n); // (arrival, departure, index)
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        customers[i] = {a, b, i};
    }

    // Sort by arrival time
    sort(customers.begin(), customers.end());

    // Min-heap: (end_day, room_number)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int room_count = 0;
    vector<int> result(n);

    for (auto &[start, end, idx] : customers) {
        if (!pq.empty() && pq.top().first < start) {
            // Room available, reuse it
            auto [free_day, room_no] = pq.top(); pq.pop();
            result[idx] = room_no;
            pq.emplace(end, room_no);
        } else {
            // Need new room
            room_count++;
            result[idx] = room_count;
            pq.emplace(end, room_count);
        }
    }

    cout << room_count << "\n";
    for (int x : result) cout << x << " ";
    cout << "\n";

    return 0;
}
