#include <iostream>
#include <queue>
#include <functional>

using namespace std;
void print(priority_queue<int, vector<int>, greater<int>> h){
    while (!h.empty())
    {
        cout<<h.top()<<" ";
        h.pop();
    }
    cout<<endl;
}
int main() {
    // priority_queue<int> h;// Max Heap
    // for min heap
     priority_queue<int, vector<int>, greater<int>> h;// greater na karke less kardega to max and ye keyword functional library ka hai
    // we code to insert only k lements for top 3
    int k=3,no;
    int i=0;

    while (1)
    {
        cin>>no;
        if (no==-1)// -1 aane pe print
        {
            print(h);
        }
        
       
    if(i<k){// means abhi tak k elements nahi aaye
        h.push(no);
        i++;
    }
    else{ // i==k
    if (no> h.top())
    {
       h.pop();
       h.push(no);
    }
    

    }
    }
    return 0;
}