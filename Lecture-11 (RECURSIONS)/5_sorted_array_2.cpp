#include <iostream>
using namespace std;
bool is_sorted(int *a, int n){
    //  base case tab hai jab 1 ya 0 elements ho and tab sorted hi hai
    if(n==0 or n==1){
        return 1;
    }
    
    // big problem: if  n terms sorted or not smaller issue if n-1 sorted or not
    if(a[n-2]<=a[n-1]){/* case A where we divide first all terms leaving the 
    last  one and taking the index as 0 of the 1st element*/
        bool chhota_sorted= is_sorted(a,n-1);
        return chhota_sorted; // or return is_sorted(a+1,n-1)
    }
    else return 0;
}
int main() {
    int a[]={1,2,9,3,5,9,6,};
    int n= sizeof(a)/sizeof(int);
    if(is_sorted(a,n)==1){
   cout<< "Array is sorted";
    }
   else cout<<"array not sorted";
    return 0;
}