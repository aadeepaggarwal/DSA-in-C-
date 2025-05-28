#include <iostream>
using namespace std;

bool binary_search(int *a,int s,int e,int key){
    
    
    //base case
    if (s>e)
    {
        cout<<"not found";
        return -1;// -1 because 0 is also an index so we return -1
    }
    
    // recursion case
   int mid= (s+e)/2;
    if (a[mid]==key)
    {
        cout<<"found at index : "<<mid;
        return 1;
    }
    else if (key>a[mid])
    {
       binary_search(a,mid+1,e,key) ;
    }
    else binary_search(a,s,mid-1,key) ;
    


}
int main() {
    int n;
    cout<<"enter the size :";
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"enter the value of "<< i<<"th index : ";
        cin>>a[i];
    }
    int key;
    cout<<"enter the key: ";
    cin>>key;
    binary_search(a,0,n-1,key);
    return 0;
}