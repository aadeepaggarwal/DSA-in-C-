// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//     int n,k; cin>>n>>k;
//     vector<int>arr(n);
//     unordered_map<int,list<int>>val_ind;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         val_ind[arr[i]].push_back(i);
//     }
//     vector<vector<int>> ans(n,vector<int>(3));
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j <n; j++)
//         {
//            int sum=arr[i]+arr[j];
//            if(val_ind.find(k-sum)!=val_ind.end()){
//                 for(auto x: val_ind[k-sum]){
//                     if(x!= i and x!=j){
//                         ans.push_back({i,j,x});
//                     }
//                 }
//            }
//         }
        
//     }
//     for(int i=0;i<ans.size();i++){
//         for(int j=0;j<3;j++){
//             cout<<ans[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr(n); // {value, original_index}
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = {x, i + 1}; // 1-based index
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = arr[i].first + arr[l].first + arr[r].first;
            if (sum == k) {
                cout << arr[i].second << " " << arr[l].second << " " << arr[r].second << "\n";
                return 0;
            } else if (sum < k) {
                l++;
            } else {
                r--;
            }
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}