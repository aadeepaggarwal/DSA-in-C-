// #include <bits/stdc++.h>
// using namespace std;
// int ans=0;
// int solve(vector<int>&arr, int sum, int k, int i){
//   // base case
//   if(i>=arr.size() or sum>k){
//     return 0;
//   }
//   if(sum==k){
//     ans++;
//     return 0;
//   }
//   // recursive case
//   int op1,op2;
//   op1= solve(arr,sum+arr[i],k,i+1);
//   op2= solve(arr,sum,k,i+1);
//   return op1+op2;

// }
// int main() {
//     int n,k;
//     cin>>n>>k;
//     vector<int>arr(n)/*,sums(n,0)*/;
    
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//         // if(i==0){
//         //     sums[0]=arr[i];
//         // }
//         // else sums[i]=sums[i-1]+arr[i];
//     }
//     // int ans=0;
//     // int pt1=0,pt2=0;
//     // while(pt2<n and pt1<=pt2){
//     //     if(sums[pt2]-sums[pt1]+arr[pt1]<k){
//     //         pt2++;
//     //     }
//     //   else if(sums[pt2]-sums[pt1]+arr[pt1]==k){
//     //     ans++;
//     //     pt2++;
//     //   }
//     //   else if((sums[pt2]-sums[pt1]+arr[pt1])>k){
//     //     pt1++;
//     //   }       
//     // }
//     // cout<<ans;
//     solve(arr,0,k,0);
//     cout<<ans;
//     return 0;
// }
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    long long n, x;
    cin >> n >> x;
    
    long long sum = 0, count = 0;
    unordered_map<long long, long long> prefixSumCount;
    prefixSumCount[0] = 1; // To handle subarrays starting from index 0
    
    for (long long i = 0; i < n; i++) {
        long long num;
        cin >> num;
        sum += num;
        
        if (prefixSumCount.find(sum - x) != prefixSumCount.end()) {
            count += prefixSumCount[sum - x];
        }
        
        prefixSumCount[sum]++;
    }
    
    cout << count << endl;
    
    return 0;
}
