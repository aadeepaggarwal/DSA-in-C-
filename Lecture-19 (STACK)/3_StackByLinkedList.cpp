#include <iostream>
using namespace std;
template <typename U>
class node
{
public:
    U /*int*/ data;
    node<U> /*yaha dalna pada template ke karan*/ *next;
    // constructor
    node(U d) : data(d), next(NULL) {}
};
template <typename T>
class Stack
{
public:
    node<T> *head;
    Stack()
    {
        head = NULL;
    }
    void push(T d)
    {
        node<T> *n = new node<T>(d);
        n->next = head;
        head = n;
    }
    void pop()
    {
        if (head == NULL)
        {
            return;
        }
        node<T> *temp = head;
        head = head->next;
        delete temp;
    }
    bool empty()
    {
        return head == NULL;
    }
    T top()
    {
        return head->data;
    }
};
int main()
{
    // template bana tha isilye ab ham stack normally <int> use kar sakte hain
    // Stack<int>s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);
    Stack<char> s;
    s.push('A');
    s.push('B');
    s.push('C');
    s.push('D');
    s.push('E');
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}