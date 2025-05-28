#include <iostream>
using namespace std;
template<typename T>/*make this for <int > jaha jaha array banaya waha int* ki jagah T* karde*/
class Vector{
public:
 T *arr;/*yaha * hai kyonki dma karna hai taaki size badal sake baad mein*/
 int max_size/*capacity*/;
 int curr_size/*size*/;

 Vector(int s=1){
    curr_size=0;
    max_size=s;
    arr=new int[max_size];
 }
 void push_back(T d){
    if (curr_size==max_size)
    {
        T *old_array=arr;
        int oldms=max_size;
        arr= new int [2*max_size];
        max_size*=2;
        for (int i = 0; i < oldms; i++)
        {
            arr[i]=old_array[i];
        }
        delete[]old_array;
    }
    arr[curr_size++]=d;// agar double anhi karrhe ya even if kara to ab cs ki position pe put d
   }
void pop_back(){ 
    if (curr_size>0)
    {
        curr_size--;/*baaki cs-- karne pe last element ki memory garbage ho jayegi ab unaccesible*/
    }
    
  }
int capacity(){ return max_size;  }
int size(){  return curr_size; }

T operator[](int index){
    return arr[index];// because arr is pointing on the main array jo bana hai
}
};
int main() {
    // do operator overlaoding to access vector [ issey]
    Vector<int> v;// yaha ab<d_type>lele kyonki template banwa diya
    for (int i = 0; i < 6; i++)
    {
        v.push_back(i);
        cout<<"After insertion of "<< i<<" Size: "<<v.size()<<" , capacity: "<<v.capacity()<<endl;
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]/*yaha use hoga operator overloading ka*/<<" ";
    }
    cout<<'\n';
    
    return 0;
}