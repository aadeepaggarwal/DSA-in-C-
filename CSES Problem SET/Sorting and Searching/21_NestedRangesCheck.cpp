#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;cin>>n;
    vector<pair<int,int>> arr(n);
    map<pair<int,int>,int> freq;
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        freq[{arr[i].first,arr[i].second}]=i;
    }
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans(2,vector<int>(n,0));
    for(int i=0;i<n;i++){
        bool iscont=0;
        bool contained=0;
        int pt=i+1;
        // front check to see if it contains 
        while(!iscont and pt<n){
            if(arr[i].second>=arr[pt].second){
                iscont=1;
                break;
            }
            pt++;
        }
        pt=i-1;
        // back check for its container 
        while(!contained and pt>=0){
            if(arr[i].second<=arr[pt].second){
                contained=1;
                break;
            }
            pt--;
        }
        if(iscont){
            ans[0][freq[{arr[i].first,arr[i].second}]]=1;
        }
        if(contained){
            ans[1][freq[{arr[i].first,arr[i].second}]]=1;
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}