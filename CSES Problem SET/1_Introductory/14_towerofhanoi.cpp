#include <iostream>
using namespace std;
void solve(int n, int src, int helper, int dest){
    if(n==0) return;
    
    solve(n-1,src,dest, helper);
    cout<<src<<" "<<dest<<endl;
    solve(n-1,helper,src,dest);
    return;
}
int main() {
    int n;
    cin>>n;
    int src=1, helper=2, dest=3;
    cout << (1<<n) - 1 << endl;
    solve(n,src,helper, dest);
    return 0;
}