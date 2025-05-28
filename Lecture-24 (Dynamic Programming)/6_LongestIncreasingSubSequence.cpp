#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
void solve(){

}
int main() {
    int a[]={10,9,3,5,4,11,7,8};
    int n= sizeof(a)/sizeof(int);
    int dp[1000];
    for (int i = 0; i < n; i++)
    {
        dp[i]=1;// intially sab 1
    }
    for (int i = 1; i < n; i++)
    {
        int ans=1;// agar ek hai to ans =1 
        for (int j = i-1; j>=0; j--)
        {
            if (a[j]<a[i])
            {
                ans=max(ans,dp[j]+1);// agar chhota wala mil gaya to find its dp and do sum
            }
            
        }
        dp[i]=ans;
    }
    int f_ans=0;
    for (int i = 0; i < n; i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    int indx;
    for (int i = 0; i < n; i++)
    {
        if(dp[i]>f_ans){
            f_ans=dp[i];
            indx=i;
        }
    }
    
    cout<<endl<<f_ans<<endl;
// this part is to print the max wala sequence as well
    vector<int> list;
    int element=a[indx];
    f_ans--;
    list.push_back(element);
    int i=indx-1;
    while (f_ans>0)
    {
       if (a[i]<element and f_ans==dp[i])
       {
        list.push_back(a[i]);
        element=a[i];
        f_ans--;
       }
       i--;
    }
    
    for (int i = list.size()-1; i >=0; i--)
    {
        cout<<list[i]<<" ";// ulta array print karde bas
    }
    
    
    return 0;
}