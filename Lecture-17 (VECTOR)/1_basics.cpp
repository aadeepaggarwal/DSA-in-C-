#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> v;
  for (int i = 0; i < 5; i++)
  {
    v.push_back(i);
    cout<<"After insertion of "<< i<<" Size: "<<v.size()<<" , capacity: "<<v.capacity()<<endl;
    
  }
   
    return 0;
}
