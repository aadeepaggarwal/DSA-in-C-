#include <iostream>
using namespace std;
void staircase(int a[][4],int n,int m,int key){
    int i=0, j=m-1;// set the iterators at the last element of 1st row
    while(i<n and j>=0){
        if (a[i][j]==key)
        {// agar key found then print index and return 
            cout<<"Key found at index "<<i<<" and "<<j;
            return;
        }
        else if(key>a[i][j]){// if key is larger then go down hence row increase hence i++
            i++;
        }
        else j--;// else if means key is smaller so go left means column less means j--
        
    }
    cout<<"key not found! ";// now if we came out of the loop means element not found index over so print not found
    return;// even if we dont write return code works void mein yaha
}
int main() {
    int key;
    cout<<"enter the key :";
    cin>>key;
    int a[][4]={
        {1,2,3,4},
        {2,4,5,10},
        {6,7,9,12},
        {7,8,15,19}
    };
    int n= sizeof(a)/sizeof(a[0]);// number of rows
    int m= sizeof(a[0])/sizeof(int);// number of coulmns
    staircase(a,n,n,key);
    return 0;
}