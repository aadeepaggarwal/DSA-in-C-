#include <iostream>
using namespace std;

int binarysearch(int a[],int n, int key){
     int low=a[0];
    int  mid;
    int high=a[n-1];
    
    while(low<=high){
        
        mid=(low+high)/2; // can divide like this (low+mid)>>1 because right shift means divided by 2
        if (a[mid]>key){
            high=mid-1;
            
        }
        else if(a[mid]<key){
            low=mid+1;
            
        }
        else{
            cout<<"yes found at index : "<< mid;
            return 0 ;
        }

    }
    if(low>high){
        cout<<"not found";
        return 0;
    }
}
int main() {
    int array[5]={1,2,3,4,5};
   int n=sizeof(array)/sizeof(int);
    int key;
    cout<<"enter key";
    cin>> key;
    binarysearch( array,n, key);
    
    
    return 0;
}