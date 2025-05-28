#include <iostream>
using namespace std;
int main() {
    int a[100]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(int);
    cout<< n;// it will  be 100 because total size is N which is 100
    return 0;
}