#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& apples, int index, long long sum1, long long sum2, long long& minDiff) {
    if (index == apples.size()) {
        minDiff = min(minDiff, abs(sum1 - sum2));
        return;
    }
    
    // Include current apple in first group
    solve(apples, index + 1, sum1 + apples[index], sum2, minDiff);
    
    // Include current apple in second group
    solve(apples, index + 1, sum1, sum2 + apples[index], minDiff);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> apples(n);
    for(int i = 0; i < n; i++) {
        cin >> apples[i];
    }
    
    long long minDiff = LLONG_MAX;
    solve(apples, 0, 0, 0, minDiff);
    
    cout << minDiff << endl;
    return 0;
}