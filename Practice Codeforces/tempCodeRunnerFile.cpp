#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        int ans=0;
        ans+=b%2==0? b/2:(b+1)/2;
        if(((ans*15)-b*4)>=a){
            cout<<ans<<endl;
            
        }
        else{
            int needed=a-((ans*15)-b*4);
            ans+=(needed/15)+1;
            cout<<ans<<endl;
            
        }
    }

    return 0;
}
