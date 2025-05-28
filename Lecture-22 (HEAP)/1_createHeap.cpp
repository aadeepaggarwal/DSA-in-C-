#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class MinHeap{
    vector<int> v;
    public:
    MinHeap(){
        v.push_back(-1);//To block 0th index
    }
    void push(int d){
        v.push_back(d);
        int c=v.size()-1;
        int p=c/2;
        while(p>=1 and v[p]>v[c]){
            swap(v[p],v[c]);
            p/=2;
            c/=2;
        }
    }
    int top(){
        return v[1];
    }
    void heapify(int i){
        int left=2*i;
        int right=2*i+1;
        int minindx=i;// lets assume sabse choti value is on index i
        if(left<v.size()/*agar left valid index hai*/and v[left]<v[minindx]){
            minindx=left;
        }// filhal left wala minimum pe agaya agar right wala chhota hua to usey daldenge
        if(right<v.size() and v[right]){
            minindx=right;
        }
        if(minindx!=i/*means agar mi change hua to hi aage heapify laga warna ruk ja hence this acts as the base case here*/){
            swap(v[minindx],v[i]);// matlab minimum wala swap to kar jo heapify ka main kaam hai
            heapify(minindx);

        }

    }
    void pop(){
      swap( v[1],v[v.size()-1]);
      v.pop_back();// hence 1st element jo end mein gaya tha woh udd gaya ab
      heapify(1);
      // called heapify to maintain heap order property
    }
   bool empty(){
    return v.size()==1;
   } 
};

int main() {
    MinHeap h;
    h.push(4);
    h.push(2);
    h.push(1);
    h.push(3);
    while (!h.empty())
    {
        cout<<h.top()<<" ";
        h.pop();// pop hi delete hai
    }
    
    return 0;
}