#include <bits/stdc++.h>
using namespace std;
void solve(int n, int a, int b){
    
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n, a, b;
        cin>>n>>a>>b;
        if(a+b>n || a>n/2+1 || b>n/2+1){
            cout<<"NO\n";
        }
        else{
            solve(n,a,b);
        }
    }
    return 0;
}