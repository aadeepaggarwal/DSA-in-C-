#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,w;
    cin>>n>>w;
    vector<int> weg(n);
    for(int i=0;i<n;i++){
        cin>>weg[i];
    }
    sort(weg.begin(),weg.end());
    int p1=0,p2=n-1,ans=0;
    while(p1<=p2){
        if(weg[p1]+weg[p2]>w){
            ans++;
            p2--;
        }
        else{
            ans++;
            p2--;
            p1++;
        }
    }
    cout<<ans<<endl;

    return 0;
}