#include <iostream>
#include<queue>
using namespace std;
void reverse(queue<int> &q){
    if (q.empty())
    {
        return;
    }
    int f=q.front();
    q.pop();
    reverse(q);
    q.push(f);// yaha top wala element f mein store karaya aur reverse kari queue recursion ne and end mein f wala store karwade push se
    
}
void print(queue<int> q){
    while (!q.empty())
{
    cout<<q.front();
    q.pop();
}
cout<<endl;
}
int main() {
    queue<int>q;
   
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
print(q);
reverse(q);
print(q);

    return 0;
}