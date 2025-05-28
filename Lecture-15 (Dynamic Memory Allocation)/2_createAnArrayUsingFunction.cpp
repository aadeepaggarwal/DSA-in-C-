#include <iostream>
using namespace std;

int * CreateArray(int n){/*int * because dma ke through int *a mein create hoga ye array*/

    int *x=new int[n];

    for (int i = 0; i < n; i++)
    {
        x[i]=i+1;
    }
    return x;// we take x and not *x because we want address to be stored in 'a' which is calling the function below
     // after returning yaha se x gets deleted kyonki te static memory 
    //tha but upar wala dynamic wala heap memory ka array stays
    // and now can be pointed upon by a jo neeche se call pe ayega
}
int main() {
    int n;
    cin>>n;

    int *a= CreateArray(n);

    for (int i = 0; i < n; i++)
    {
       cout<<a[i]<<" "<<endl;
    }
    return 0;
}