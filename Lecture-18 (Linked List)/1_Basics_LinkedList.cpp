#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;

};
int main() {
    node a,b;
    a.data=1;
    b.data=2;

    a.next=&b;
    b.next=NULL;

    node* head=&a;
    while(head/*means jab tak head null nahi hai yani exist  karta hai*/){
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<"NULL";
    return 0;
}