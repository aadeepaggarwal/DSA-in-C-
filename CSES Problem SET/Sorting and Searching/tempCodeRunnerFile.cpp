#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int pt1=0,pt2=0,sums=INT_MIN;
    int ans=INT_MIN;
    while(pt2<n){
        
        if(pt2-pt1+1>=a and pt2-pt1+1<=b){
            sums+=arr[pt2];
            ans=max(ans,sums);
            if(pt2+1<n)pt2++;
        }
        if(pt2+1-pt1<a){
            sums+=arr[pt2];
            
            pt2++;
        }
        if((pt2-pt1+1==b and pt2-pt1+1>=a) or (pt2+1==n and pt2-pt1+1>=a)){
            sums-=arr[pt1--];
            ans=max(ans,sums);
        }
    }
    
    cout<<ans;
    return 0;
}