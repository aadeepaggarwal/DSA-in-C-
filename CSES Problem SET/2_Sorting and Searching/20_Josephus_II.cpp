#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;cin>>n>>k;
    deque<int>q;
    for(int i=1;i<=n;i++){
        q.push_back(i);
    }
    while(!q.empty()){
        int t=k;
        while(t--){
        int x=q.front();
        q.pop_front();
        q.push_back(x);
        }
        cout<<q.front()<<" ";
        q.pop_front();
    }
    return 0;
}