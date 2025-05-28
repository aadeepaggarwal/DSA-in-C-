#include <iostream>
using namespace std;
void bubblesort(int *a,int n,int i,int j=0){
    // base case
    if (i==n-1)
    {
        return;
    }
    
    //recursion
    //for (int j = 0; j <= n-2-i; j++) replcing the loop of j as well
   if(j<=n-2-i) {
        if (a[j]>a[j+1])
        {
            swap(a[j],a[j+1]);
        }
        bubblesort(a,n,i,j+1);// j++ loop se na karke recursion se karlia for same i

        
    }
   else bubblesort(a,n,i+1,0/*j=0*/);// we put it in else warna faltu call kardega beech mein i+1 ko

    
}
int main() {
    int n;
    cout<<"enter the size :";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"enter the value of "<< i<<"th index :";
        cin>>a[i];
    }
    bubblesort(a,n,0);
    for (int i = 0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}