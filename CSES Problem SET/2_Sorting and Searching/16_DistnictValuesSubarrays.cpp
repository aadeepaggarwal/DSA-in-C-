#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Read input array
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Two pointers to maintain the sliding window
    int pt1 = 0, pt2 = 0;
    
    // To store the number of valid subarrays
    long long ans = 0;

    // Set to track elements currently in the window
    unordered_set<int> visited;

    // Traverse through the array with pt2
    while(pt2 < n){
        // If current element already exists in the window,
        // shrink the window from the left (pt1)
        while(visited.count(arr[pt2])){
            visited.erase(arr[pt1]);
            pt1++;
        }

        // Insert current element into the set
        visited.insert(arr[pt2]);

        // Count subarrays ending at pt2 with all distinct elements
        ans += pt2 - pt1 + 1;

        // Move pt2 to the next element
        pt2++;
    }

    // Output the final answer
    cout << ans << "\n";
    return 0;
}
