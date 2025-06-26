#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin>>n;
    vector<long long>arr(n),sums(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
        
    }
    sums[0]=arr[0];
    long long ans=arr[0];
    for(long long i=1;i<n;i++){
        
        sums[i]=max(sums[i-1]+arr[i],arr[i]);
        ans=max(sums[i],ans);
    }
    cout<<ans;
    return 0;
}