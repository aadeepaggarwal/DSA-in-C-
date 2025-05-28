#include <iostream>
using namespace std;
int sum(int a,int b=0,int c=0){
    int sum=a+b+c;
    return sum;
}
int main() {
    int a=10;
    int b=20;
    int c=30;
 cout<< sum(a,b,c)<<'\n';
 cout<< sum(a,b)<<'\n';
 cout<< sum(a)<<'\n';// works because 2 parameters can be 0 default arguments used
    return 0;
}