#include <iostream>
#include <vector>
using namespace std;
int main(){
int n=10;
    vector<int> arr(n);
    // above pe we just made an array of size n
     for (int i = 0; i < n; i++)
  {
    arr.push_back(i);// ye ab 10 ke baad 11th pe karega last mein naaki 0th se
    // do ar[i]=i for 0 th bucket ke liye
  }
  // ab to avoid this in a 2d array, dont mention total columns, bas rx1 ka vectors ka array bana de aur pushback karta reh
  for (int i = 0; i < arr.size(); i++)
  {   
     cout<<arr[i]<<" ";
  }
  return 0;
  }         