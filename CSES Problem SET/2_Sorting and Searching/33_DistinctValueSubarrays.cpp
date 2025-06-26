#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;

    map<int, int> freq;
    long long ans = 0;
    int left = 0, distinct = 0;

    for (int right = 0; right < n; right++) {
        freq[arr[right]]++;
        if (freq[arr[right]] == 1)
            distinct++;

        while (distinct > k) {
            freq[arr[left]]--;
            if (freq[arr[left]] == 0)
                distinct--;
            left++;
        }

        ans += (right - left + 1);
    }

    cout << ans << endl;

    return 0;
}
