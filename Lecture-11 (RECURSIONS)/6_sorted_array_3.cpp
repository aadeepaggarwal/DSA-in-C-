#include <iostream>
using namespace std;
bool is_sorted(int *a, int i, int n){
    //  base case tab hai jab i=N-1 tab means ek hi lement bacha 
    if(i==n-1 or i==n/* agar n=0 hua toh i==n liya hai*/){
        return 1;
    }
    
    // big problem: if  n terms sorted or not smaller issue if n-1 sorted or not
    if(a[i]<=a[i+1]){/* case C where we divide next all terms leaving the 
    first  one and taking the index as same of the element earlier */
        bool chhota_sorted= is_sorted(a,i+1,n);
        return chhota_sorted; // or return is_sorted(a,i+1,n)
    }
    else return 0;
}
int main() {
    int a[]={1,2,9,3,5,9,6,};
    int n= sizeof(a)/sizeof(int);
    int i=0;
    if(is_sorted(a,i,n)==1){
   cout<< "Sorted";}
   else cout<<" not sorted";
    return 0;
}