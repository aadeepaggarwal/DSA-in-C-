#include <iostream>
using namespace std;
int sum(int n){
    // base case jab n=0 hai to answer 0 ayega isilye 0 pehle hi likhde
    if(n==0){
        return 0;
    }
    // recursive relation
    // sum(n)=n+sum(n-1)
    int chhota_ans=sum(n-1);
    int bada_ans= n+chhota_ans;
    return bada_ans;
}
int main() {
     int n;
    cout<<"enter the number for sum :";
    cin>>n;
    cout<< sum(n);
    return 0;
}