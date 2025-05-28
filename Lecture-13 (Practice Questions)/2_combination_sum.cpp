#include <iostream>
#include <vector>
using namespace std;
void solve(vector<int>&v, int target,int i, vector<int>&ans){
    // base case
    if(i==v.size()){
        if (target==0)
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<'\n';
        }
        return;
        
    }

    // recursion

    if (v[i]<=target)
    {
        ans.push_back(v[i]);// we will push this v[i] in our answer
        solve(v,target-v[i],i,ans);// ye hai pick wala caseyaha we pick v[i] and call function on it
        // ye tab hai jab sum>target hone lage to pichle wale pe return hoga isilye pop karlo
        ans.pop_back();
    }
    solve(v,target,i+1,ans);// not pick chala lo
}
int main() {
    vector<int>v={2,3,6,7};
    int target =7;
    vector<int>ans;
    solve(v,target,0,ans);
    
    return 0;
}