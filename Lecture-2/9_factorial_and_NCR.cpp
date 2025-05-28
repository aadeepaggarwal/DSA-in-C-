#include <iostream>
using namespace std;

int factorial(int n){
    int product=1;
    for (int i = 1; i <=n; i++)
    {
        product=product*i;
    }
    return product;
    
}

int NCR(int N,int R){
    int NCR_= factorial(N)/(factorial(R)*factorial(N-R));
    return NCR_;
}
int main() {
     int N,R;
    cout<<"enter the value of N  and R:";
    cin>>N>>R;
    cout<<NCR(N,R);
    return 0;
}