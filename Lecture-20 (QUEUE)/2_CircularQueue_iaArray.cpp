#include <iostream>
using namespace std;
class Queue{
    public:
     int *a;
     int n;
     int f,e,cs;
Queue(int n=5){
    this->n=n;
    cs=0;
    f=0;
    e=-1;
    a=new int[n];
}

void push(int d){
    if (cs<n)
    {
       e=(e+1)%n;
       a[e]=d;
       cs++;
    }
    else{
        cout<<"Queue Overflow \n";
    }
    
}

void pop(){
    if (cs>0)
    {
       f=(f+1)%n;
       cs--;
    }
    else cout<<"Queue Underflow\n";
    
}
bool empty(){
    return cs==0;
}
int front(){
    return a[f];
}
};
int main() {
     Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

while (!q.empty())
{
    cout<<q.front();
    q.pop();
}
    return 0;
}