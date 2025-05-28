#include <iostream>
#include <queue>
using namespace std;
template<typename T>
class Stack{
    public:
    queue<T> q1,q2;
    
    void push(T d){
        // if(!q1.empty() || (q1.empty() and q2.empty())){
        //     q1.push(d);
        // }
        // else if(!q2.empty){
        //     q2.push(d);
        // }
        if (!q2.empty()) q2.push(d);
    else q1.push(d);
    }
    void pop(){
        if(!q1.empty()){
            while (q1.size()>1)
            {
               T f=q1.front();
               q1.pop();
               q2.push(f);

            }
            // dont store last element bas delete it by pop kyonki pop hai ye
            
            q1.pop();
            
        }
        else{
            while (q2.size()>1)
            {
              T f=q2.front();
               q2.pop();
               q1.push(f);

            }
            // dont store last element bas delete it by pop kyonki pop hai ye
            
            q2.pop();
        }
    }
    T top(){
         if(!q1.empty()){
            while (q1.size()>1)
            {
              T f=q1.front();
               q1.pop();
               q2.push(f);

            }
            // dont store last element bas delete it by pop kyonki pop hai ye
            T x=q1.front();
            q1.pop();
            q2.push(x);
            return x;
        }
        else{
            while (q2.size()>1)
            {
              T f=q2.front();
               q2.pop();
               q1.push(f);

            }
            // dont store last element bas delete it by pop kyonki pop hai ye
            
           T x=q2.front();
            q2.pop();
            q1.push(x);
            return x;
        }
    }
    bool empty(){
        return (q1.empty() and q2.empty());
        
    }
};

int main() {
    Stack <char>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while (!s.empty())
    {
        cout<< s.top()<<" ";
        s.pop();
    }
    return 0;
}