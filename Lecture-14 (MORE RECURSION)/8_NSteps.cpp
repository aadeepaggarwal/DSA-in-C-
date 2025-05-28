#include <iostream>
using namespace std;

int Nsteps(int n,int k){
    // base case
    if (n==0)
    {
        return 1;
    }
    // else if(n==1 or n==2) return 1;
    // else if(n==2) return 2;   --> only for k=3 wala case
    if (n<0)
    {
        return 0;
    }
    
    

    // recursive case
   // return Nsteps(n-1)+ Nsteps(n-2)+Nsteps(n-3);
    // above ke liye we had assumes 3 steps as max 
    // let us say k== steps max jo we can take on one go
    int ans=0;
    for (int i = 1; i <= k; i++)
    {
        ans+= Nsteps(n-i,k);
    }
    return ans;
    

}
int main() {
    int n,k;
    cout<<"enter the total steps and jump size : ";
    cin>>n>>k;
    cout<<Nsteps(n,k);
    return 0;
}