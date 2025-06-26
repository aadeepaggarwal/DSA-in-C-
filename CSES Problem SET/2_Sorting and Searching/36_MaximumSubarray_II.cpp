// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     int n,a,b;
//     cin>>n>>a>>b;
//     vector<int>arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }
//     int pt1=0,pt2=0,sums=INT_MIN;
//     int ans=INT_MIN;
//     while(pt2<n){
        
//         if(pt2-pt1+1>=a and pt2-pt1+1<=b){
//             sums+=arr[pt2];
//             ans=max(ans,sums);
//             if(pt2+1<n)pt2++;
//         }
//         if(pt2+1-pt1<a){
//             sums+=arr[pt2];
            
//             pt2++;
//         }
//         if((pt2-pt1+1==b and pt2-pt1+1>=a) or (pt2+1==n and pt2-pt1+1>=a)){
//             sums-=arr[pt1--];
//             ans=max(ans,sums);
//         }
//     }
    
//     cout<<ans;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> arr(n), prefix_sum(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }

    multiset<long long> ms;
    long long ans = LLONG_MIN;

    for (int i = a; i <= n; i++) {
        
        // Insert prefix_sum[i - a] into multiset (possible valid subarray start)
        ms.insert(prefix_sum[i - a]);

        // Find minimum prefix sum to maximize subarray sum
        ans = max(ans, prefix_sum[i] - *ms.begin());

        // Remove prefix_sum[i - b] to keep window size within [a, b]
        if (i - b >= 0) {
            ms.erase(ms.find(prefix_sum[i - b]));
        }
    }

    cout << ans << endl;
    return 0;
}
