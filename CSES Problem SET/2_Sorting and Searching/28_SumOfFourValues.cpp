#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    vector<int>arr(n);
    unordered_map<int,vector<pair<int,int>>>pos;
    for (int i = 0; i < n; i++) {
        cin>>arr[i];        
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int sum=arr[i]+arr[j];
            pos[sum].push_back({i,j});
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];
            int rem = k - sum;
            if (pos.find(rem) != pos.end()) {
                for (auto x : pos[rem]) {
                    // Ensure all indices are distinct
                    if (i != j && i != x.first && i != x.second && j != x.first && j != x.second && x.first != x.second) {
                        cout << i + 1 << " " << j + 1 << " " << x.first + 1 << " " << x.second + 1 << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}