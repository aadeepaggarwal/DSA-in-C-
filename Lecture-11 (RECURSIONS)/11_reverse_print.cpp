#include <iostream>
using namespace std;
// global declaration of keys
string keys[10]={ // or do 2d array where we only output via keys[lastdigit] row nahi batayi because 0 likhne pe sirf 1st alphabet aata char array se
   "zero" ,"one","two","three","four","five","six","seven","eight","nine"
};
void reverse_print(int n){
    // base case when number ==0
    if(n==0)  return;
    // recursive part
    int last_digit=n%10;
    cout<<keys[last_digit]<<" ";
    return ( reverse_print(n/10));
}
int main() {
     int n;
    cin>>n;
     reverse_print(n);
    return 0;
}