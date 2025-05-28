#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    // default constructor

    // constructor to pass value on creation
    node(int d)
    {
        data = d;
        next = NULL;
    }
};
void insertAtend(node *&head, node *&tail, int data)
{                             // node* type ki bucket hai and & for call by reference
    node *n = new node(data); // dono case mein aata bas ab neeche case check karle
    if (head == NULL)
    {
        head = tail = n;
    }
    else
    {
        tail->next = n;
        tail = n;
        // and n already deafult constructor se jab bana to null pe point karrha tha
    }
}
int FindMiddle(node *&head, node *&tail){
    
    if (!head ||!head->next)
    {
        return head->data;
    }
    node*f=head->next, *s=head;
    while (f and f->next)
    {
        f=f->next->next;
        s=s->next;
    }
    return s->data;
    
}
int main() {
    node* head=NULL, *tail=NULL;

    insertAtend(head, tail, 1);
    insertAtend(head, tail, 2);
    insertAtend(head, tail, 3);
    insertAtend(head, tail, 4);
    insertAtend(head, tail, 5);
    insertAtend(head, tail, 6);
    insertAtend(head, tail, 7);
    cout<<FindMiddle(head,tail);
    return 0;
}