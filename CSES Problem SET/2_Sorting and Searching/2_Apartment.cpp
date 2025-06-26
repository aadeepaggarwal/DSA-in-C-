#include <bits/stdc++.h>

using namespace std;
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> people(n);
    vector<int> houses(m);
    for(int i=0;i<n;i++){
        cin>>people[i];
    }
    for(int i=0;i<m;i++){
        cin>>houses[i];
    }
    sort(people.begin(),people.end());
    sort(houses.begin(),houses.end());

    int p1=0,p2=0,ans=0;
    while(p1<n and p2<m){
        int ll=people[p1]-k;
        int ul= people[p1]+k;
        if(houses[p2]<ll){
            p2++;
        }
        else if(houses[p2]>ul){
            p1++;
        }
        else{
            ans++;
            p1++;
            p2++;
        }
    }
    cout<<ans;

    return 0;
}