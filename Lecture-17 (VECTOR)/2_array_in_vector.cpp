#include <iostream>
#include<vector>
using namespace std;

void print(vector<int> &a){
    for (int i = 0; i < a.size(); i++)
    {   
       cout<<a[i]<<" ";
    }
    
}

void update(vector<int> &a/*& le warna time n^2 lagega*/){
    for (int i = 0; i < a.size(); i++)
    {
       a[i]=i+1;
    }
    
}
int main() {
    int n=10;
    vector<int> arr(n);
    // above pe we just made an array of size n
     for (int i = 0; i < 5; i++)
  {
    arr[i]= i;
    
  }

    // to set all values as as a number say -1;
     vector<int> arr2(n,-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr2[i]<<" ";
    }

// calling a vector pe function goes by reference
// it makes a copy of vector upar
cout<<endl;
print(arr);
    return 0;
}