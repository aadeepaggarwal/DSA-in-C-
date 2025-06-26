#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,ans=0;
    cin>>n;
    vector<int>arr(n),freq(n+1,-1);
    for(int i=0;i<n;i++){
        cin>>arr[i];

    }
    
    for(int i=0;i<n;i++){
        freq[arr[i]]=1;
        if(freq[arr[i]-1]==-1)ans++;
        
    }
    cout<<ans;
    return 0;
}