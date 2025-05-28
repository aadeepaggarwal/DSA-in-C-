#include <iostream>
using namespace std;
void find_a_digit(int *a,int n,int key,int i){// puchh 0th pe hai check karke baki recursion i+1 dekhega
 // or take f(a,n) and call on f(a+1,n-1)
 // base if i=n
 bool flag=0;
 if( i==n){ 
    
    return ;}
 
 if( i==n and flag==0){ 
    cout<<"not found";
    return ;}
 // recursion
 
    if(a[i]==key){
        flag=1;
         cout<<"found at index "<< i<<"\n ";
         find_a_digit(a,n,key,i+1);
        // return;
        }
    else find_a_digit(a,n,key,i+1);
}
int main() {
    int n,key;
    cout<<"enter the size and key : ";
    cin>>n>>key;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"enter the element at index "<<i<<" ";
        cin>>a[i];
    }
    find_a_digit(a,n,key,0);
    
    return 0;
}